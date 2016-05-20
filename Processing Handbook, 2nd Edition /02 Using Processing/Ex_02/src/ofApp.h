#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        ofBackground(0);         // Set the black background
        ofSetColor(255);         // Set line value to white
        ofSetLineWidth(5);       // Set line width to 5 pixels
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
 
 // Processing code
 
 background(0);         // Set the black background
 stroke(255);           // Set line value to white
 strokeWeight(5);       // Set line width to 5 pixels
 
 line(10, 80, 30, 40);  // Left line
 line(20, 80, 40, 40);
 line(30, 80, 50, 40);  // Middle line
 line(40, 80, 60, 40);
 line(50, 80, 70, 40);  // Right line
 
*/