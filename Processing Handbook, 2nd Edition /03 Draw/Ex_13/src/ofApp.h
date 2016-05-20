#pragma once

#include "ofMain.h"

// openFrameworks ofDrawTriangle API does not support the concept of a stroke
// so we mimic it via writing a helper function that leverages ofPath to draw
// a triangle with a stroke

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        ofSetWindowShape(100, 100);
    }
    void draw()
    {
        triangle(60, 10, 25, 60, 75, 65);  // Filled triangle
        ofSetColor(0);
        ofDrawLine(60, 30, 25, 80);  // Outlined triangle edge
        ofDrawLine(25, 80, 75, 85);  // Outlined triangle edge
        ofDrawLine(75, 85, 60, 30);  // Outlined triangle edge
    }
    void triangle(float x1,float y1,float x2,float y2,float x3, float y3)
    {
        ofPath p = ofPath();
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.moveTo(x1,y1);
        p.lineTo(x2,y2);
        p.lineTo(x3,y3);
        p.close();
        p.draw();
    }
};



/*
 
 // reference Processing code
 
 triangle(60, 10, 25, 60, 75, 65);  // Filled triangle
 line(60, 30, 25, 80);  // Outlined triangle edge
 line(25, 80, 75, 85);  // Outlined triangle edge
 line(75, 85, 60, 30);  // Outlined triangle edge
 
 */
