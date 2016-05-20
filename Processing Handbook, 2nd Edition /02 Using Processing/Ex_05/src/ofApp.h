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
        ofBackground(204);
        // Assign the horizontal value of the cursor to x
        float x = mouseX;
        // Assign the vertical value of the cursor to y
        float y = mouseY;
        ofDrawLine(x, y, x+20, y-40);
        ofDrawLine(x+10, y, x+30, y-40);
        ofDrawLine(x+20, y, x+40, y-40);
    }
};




/*
 
    void setup() {
      size(100, 100);
    }

    void draw() {
      background(204);
      // Assign the horizontal value of the cursor to x
      float x = mouseX;
      // Assign the vertical value of the cursor to y
      float y = mouseY;
      line(x, y, x+20, y-40);
      line(x+10, y, x+30, y-40);
      line(x+20, y, x+40, y-40);
    }
 
 
 */