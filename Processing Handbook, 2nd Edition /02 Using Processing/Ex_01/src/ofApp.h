#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        ofSetColor(0, 0, 0);        // set line color to black
    }
    void draw()
    {
        ofDrawLine(10, 80, 30, 40);  // Left line
        ofDrawLine(20, 80, 40, 40);
        ofDrawLine(30, 80, 50, 40);  // Middle line
        ofDrawLine(40, 80, 60, 40);
        ofDrawLine(50, 80, 70, 40);  // Right line
    }
};



/*
 
     // reference Processing code
     
     line(10, 80, 30, 40);  // Left line
     line(20, 80, 40, 40);
     line(30, 80, 50, 40);  // Middle line
     line(40, 80, 60, 40);
     line(50, 80, 70, 40);  // Right line
 
 */
