#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        ofSetWindowShape(100, 100);
    }
    
    void draw()
    {
        ellipse(40, 40, 60, 60);  // Large circle
        ellipse(75, 75, 32, 32);  // Small circle
    }
    
    // float: x-coordinate of the ellipse
    // float: y-coordinate of the ellipse
    // float: width of the ellipse by default
    // float: height of the ellipse by default
    
    void ellipse(float x,float y, float width, float height)
    {
        ofPath p = ofPath();
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.ellipse(x,y,width,height);
        p.draw();
    }
};





/*
 
 // reference Processing code
 
 ellipse(40, 40, 60, 60);  // Large circle
 ellipse(75, 75, 32, 32);  // Small circle
 
 */