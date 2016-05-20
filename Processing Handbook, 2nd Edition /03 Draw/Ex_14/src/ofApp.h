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
        triangle(55, 9, 110, 100, 85, 100);
        triangle(55, 9, 85, 100, 75, 100);
        triangle(-1, 46, 16, 34, -7, 100);
        triangle(16, 34, -7, 100, 40, 100);
    }
    void triangle(float x1,float y1,float x2,float y2,float x3, float y3)
    {
        ofFill();
        ofSetColor(255, 255, 255); //fill color
        ofDrawTriangle(x1, y1, x2, y2, x3, y3);
        ofNoFill();
        ofSetColor(0, 0, 0);    //stroke color
        ofDrawTriangle(x1, y1, x2, y2, x3, y3);
    }
};



/*
 
 // reference Processing code
 
 triangle(55, 9, 110, 100, 85, 100);
 triangle(55, 9, 85, 100, 75, 100);
 triangle(-1, 46, 16, 34, -7, 100);
 triangle(16, 34, -7, 100, 40, 100);
 
 */
