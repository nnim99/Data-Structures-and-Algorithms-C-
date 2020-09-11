//
//  Vertex.swift
//  Never Get Lost
//
//  Created by Yusra Khalid on 1/7/18.
//  Copyright © 2018 Yusra Khalid. All rights reserved.
//

import Foundation
import MapKit

class Vertex{
    var name: Int;
    var h: Double; // distance between selected vertex and destination
    var g: Double; //distance between last vertex to this selected vertex
    var f: Double;
    var parent:Int
    var destination:Int;
    var p = MapPoints() // creating object of mappoints to access points of graph from other class
    
//    constructor to initilize object with destination and parent
//    value of g,h,f are set as 0. it will change on update
    init(name:Int, destination:Int, parent:Int) {
        self.destination = destination
        self.name = name
        self.g = 0.0
        self.h = 0.0
        self.f = g+h
        self.parent = parent
    }
    
    func distance(other: Vertex) -> Double {
       return MKMetersBetweenMapPoints(p.points[self.name], p.points[other.name])
    }
    
//    on updating the parent of a vertex it's g, h, and f value will be updated
    func update(parent:Int, gScore: Double) {
        self.parent = parent
        self.g = MKMetersBetweenMapPoints(p.points[self.name], p.points[parent]) + gScore
        self.h = MKMetersBetweenMapPoints(p.points[self.name], p.points[destination])
        self.f = g+h
    }
}




