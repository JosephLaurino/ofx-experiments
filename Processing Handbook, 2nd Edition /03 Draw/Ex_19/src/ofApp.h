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
    void ellipse(float x,float y, float w, float h)
    {
        ofPath p = ofPath();
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.ellipse(x,y,w,h);
        p.draw();
        ofPath::Mode mode;
    }
};





/*
 
 // reference Processing code
 
 ellipse(40, 40, 60, 60);  // Large circle
 ellipse(75, 75, 32, 32);  // Small circle
 
 */