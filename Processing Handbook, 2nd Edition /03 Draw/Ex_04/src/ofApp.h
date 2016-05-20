#pragma once

#include "ofMain.h"

// OF does not have a equivalent point() function, simulating it with
// drawing of a circle with radius 1

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        ofSetWindowShape(100, 100);
        ofSetColor(0, 0, 0);
    }
    void draw()
    {
        // Points with the same X and Y parameters
        // form a diagonal line from the
        // upper-left corner to the lower-right corner
        ofDrawCircle(20, 20, 1);
        ofDrawCircle(30, 30, 1);
        ofDrawCircle(40, 40, 1);
        ofDrawCircle(50, 50, 1);
    }
};



/*
 
    // reference Processing code
     
    // Points with the same X and Y parameters 
    // form a diagonal line from the  
    // upper-left corner to the lower-right corner 
    point(20, 20); 
    point(30, 30); 
    point(40, 40); 
    point(50, 50); 
    point(60, 60);
 
 */