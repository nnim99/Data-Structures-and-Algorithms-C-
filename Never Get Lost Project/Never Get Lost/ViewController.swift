//
//  ViewController.swift
//  Never Get Lost
//
//  Created by Yusra Khalid on 1/7/18.
//  Copyright © 2018 Yusra Khalid. All rights reserved.
//

import UIKit
import MapKit

class ViewController: UIViewController {
    @IBOutlet weak var mapView: MKMapView!
    let maps = MapPoints()
    var customDelegate: MapViewCustomDelegate?
    

    override func viewDidLoad() {
        super.viewDidLoad()
        let initialLocation = CLLocation(latitude: 33.643786, longitude: 72.986562);
        customDelegate = MapViewCustomDelegate(mapView: mapView, viewController: self)
        mapView.delegate = customDelegate
        
        for i in 0...maps.points.count - 1 {
            let artwork = Artwork(title: String(i),
                                  coordinate: CLLocationCoordinate2D(latitude: maps.points[i].x, longitude: maps.points[i].y))
            self.mapView.addAnnotation(artwork)
        }
        
        let regionRadius: CLLocationDistance = 2000
        func centerMapOnLocation(location: CLLocation) {
            let coordinateRegion = MKCoordinateRegionMakeWithDistance(location.coordinate,
                                                                      regionRadius, regionRadius)
            mapView.setRegion(coordinateRegion, animated: true)
        }
        
        centerMapOnLocation(location: initialLocation)
        
//        every possible path has been tested
//        for i in 0...61{
//            for j in 0...61{
//                if (i != j){
//                    let d = AAsterik(start: i, end: j)
//                    var q = d.pathFinding()
//                    for v in q{
//                        print(v , "\n")
//                    }
//                    print("\n \n \n")
//                }
//            }
//        }
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

