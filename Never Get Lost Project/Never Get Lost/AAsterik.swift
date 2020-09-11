//
//  AAsterik.swift
//  Never Get Lost
//
//  Created by Yusra Khalid on 1/7/18.
//  Copyright © 2018 Yusra Khalid. All rights reserved.
//

import Foundation
import MapKit

class AAsterik{
    var start:Int
    var end:Int
    var open:[Int] = []
    var closed:[Int] = []
    var v = Vertex(name: -1, destination: -1, parent: -1) // creating object of vertex to access it's info
    var vertices:[Vertex] = []
    var gScore: [Double] = []

    init(start:Int, end:Int){
        self.start = start
        self.end = end
        open = []
        closed = []
        for i in 0...v.p.points.count - 1{
            let v = Vertex(name: i, destination: self.end, parent: -1)
            vertices.append(v)
            gScore.append(9999999)
        }
        
    }
    
    func getLowestNode() -> Int {
        var min:Int = open[0]
        var index:Int = 0
        for n in 0...open.count - 1 {
            if vertices[open[n]].f < vertices[min].f {
                min = open[n];
                index = n
            }
        }
        open.remove(at: index)
        return min
    }
    
    func getPath() -> [Int] {
        var temp:Int = end
        var path:[Int] = []
        
        path.append(end)
        while (temp != start){
            path.append(vertices[temp].parent)
            temp = vertices[temp].parent
        }
        return path
        
    }
    
    func pathFinding() -> [Int] {
        var current = self.start
        
        gScore[start] = 0
        open.append(start)
        
        while (!open.isEmpty){
            current = getLowestNode()
            
            if (current == end){
                return getPath()
            }
            
            closed.append(current)
            
            for neighbour in v.p.links[current]{
                var flag = true
                for k in open{
                    if (k == neighbour){
                        flag = false
                    }
                }
                for l in closed {
                    if (l == neighbour){
                        flag = false
                    }
                }
                if (flag){
                    open.append(neighbour)
                }
                
                // The distance from start to a neighbor
                //the "dist_between" function may vary as per the solution requirements.
                let tentative_gScore = gScore[current] + vertices[current].distance(other: vertices[neighbour])
                if tentative_gScore >= gScore[neighbour] {
                    continue        // This is not a better path.
                }
                
                // This path is the best until now. Record it!
                vertices[neighbour].update(parent: current, gScore: gScore[current])
                gScore[neighbour] = tentative_gScore
            }
        }
        return []
    }
}

