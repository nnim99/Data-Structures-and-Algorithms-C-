//
//  MapViewCustomDelegate.swift
//  Never Get Lost
//
//  Created by Yusra Khalid on 1/7/18.
//  Copyright © 2018 Yusra Khalid. All rights reserved.
//

import Foundation
import MapKit

class MapViewCustomDelegate: NSObject, MKMapViewDelegate {
    
    var start: Int = -1
    var end: Int = -1
    var startSelected: Bool = false
    let maps = MapPoints()
    weak var mapView: MKMapView!
    weak var viewController: ViewController?
    
    init(mapView: MKMapView, viewController: ViewController?) {
        self.mapView = mapView
        self.viewController = viewController
        super.init()
    }
    
    func resetDefault() {
        start = -1
        end = -1
        startSelected = false
    }
    
    func findPath() {
        let d = AAsterik(start: self.start, end: self.end)
        let p = d.pathFinding()
        drawPath(points: p)
    }
    
    func drawPath(points: [Int]){
        
        var locations = points.map {
            CLLocationCoordinate2D(latitude: self.maps.points[$0].x, longitude: self.maps.points[$0].y)
        }
        let polyline = MKPolyline(coordinates: &locations, count: locations.count)
        mapView.add(polyline)
    }
    
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        print ("overlay function called")
        if overlay is MKPolyline {
            let polylineRenderer = MKPolylineRenderer(overlay: overlay)
            polylineRenderer.strokeColor = UIColor.blue
            polylineRenderer.lineWidth = 5
            return polylineRenderer
        }
        return MKOverlayRenderer()
    }
    
    func mapView(_ mapView: MKMapView, didSelect: MKAnnotationView) {
        
        guard let annotation = didSelect.annotation as? Artwork else { return }
        let id = Int(annotation.title!)!
        
        var message = ""
        var buttonText = ""
        
        if startSelected {
            message = "Select current position as EndPoint?"
            buttonText = "Endpoint"
        } else {
            message = "Select current position as StartPoint?"
            buttonText = "StartPoint"
        }
        
        //Creating UIAlertController and
        //Setting title and message for the alert dialog
        let alertController = UIAlertController(title: "Select Location?", message: message, preferredStyle: .alert)
        
        //the confirm action taking the inputs
        let confirmAction = UIAlertAction(title: buttonText, style: .default) { (_) in
            
            if self.startSelected {
                self.end = id
                self.findPath()
                
                self.resetDefault()
            } else {
                self.startSelected = true
                self.start = id
            }
        }
        
        //the cancel action doing nothing
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel) { (_) in }
        
        //adding the action to dialogbox
        alertController.addAction(confirmAction)
        alertController.addAction(cancelAction)
        
        //finally presenting the dialog box
        viewController?.present(alertController, animated: true, completion: nil)
    }
}

