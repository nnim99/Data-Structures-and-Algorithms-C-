//
//  Artwork.swift
//  Never Get Lost
//
//  Created by Yusra Khalid on 1/7/18.
//  Copyright © 2018 Yusra Khalid. All rights reserved.
//

import Foundation
import MapKit

class Artwork: NSObject, MKAnnotation {
    let title: String?
    let coordinate: CLLocationCoordinate2D
    
    init(title: String, coordinate: CLLocationCoordinate2D) {
        self.title = title
        self.coordinate = coordinate        
        super.init()
    }
    
    var subtitle: String? {
        return title
    }
}
