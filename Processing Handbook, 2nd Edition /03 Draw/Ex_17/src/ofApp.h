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
        rect(15, 15, 40, 40);  // Large square
        rect(55, 55, 25, 25);  // Small square
    }
    void rect(float x,float y, float w, float h)
    {
        ofPath p = ofPath();
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.moveTo(x,y);
        p.lineTo(x+w,y);
        p.lineTo(x+w,y+h);
        p.lineTo(x,y+h);
        p.close();
        p.draw();
    }
};





/*
 
 // reference Processing code
 
 rect(15, 15, 40, 40);  // Large square
 rect(55, 55, 25, 25);  // Small square
 
 */

