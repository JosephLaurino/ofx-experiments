#pragma once

#include "ofMain.h"


// openFrameworks does not offer a quad API so we mimic it via writing a helper function
// that leverages ofPath to draw a quad with a stroke

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        
    }
    void draw()
    {
        quad(38, 31, 86, 20, 69, 63, 30, 76);
    }
    void quad(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4)
    {
        ofPath p = ofPath();
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.moveTo(x1,y1);
        p.lineTo(x2,y2);
        p.lineTo(x3,y3);
        p.lineTo(x4,y4);
        p.close();
        p.draw();
    }
};





/*
 
 // reference Processing code
 
 quad(38, 31, 86, 20, 69, 63, 30, 76);
 
 */

