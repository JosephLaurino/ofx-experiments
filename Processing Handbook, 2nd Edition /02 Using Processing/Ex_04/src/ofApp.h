#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
    int x = 0;   // Set the horizontal position
    int y = 55;  // Set the vertical position

    
public:
    void setup()
    {
        ofSetColor(0, 0, 0);        // set line color to black
    }
    void draw()
    {
        ofBackground(204);
        ofDrawLine(x, y, x+20, y-40);     // Left line
        ofDrawLine(x+10, y, x+30, y-40);  // Middle line
        ofDrawLine(x+20, y, x+40, y-40);  // Right line
        x = x + 1;      // Add 1 to x
        if (x > 100) {  // If x is greater than 100,
            x = -40;    // assign -40 to x
        }
    }
    
};





/*
 
    // reference Processing code
 
    int x = 0;   // Set the horizontal position
    int y = 55;  // Set the vertical position

    void setup() {
      size(100, 100);  // Set the window to 100 x 100 pixels 
    }

    void draw() {
      background(204);
      line(x, y, x+20, y-40);     // Left line 
      line(x+10, y, x+30, y-40);  // Middle line 
      line(x+20, y, x+40, y-40);  // Right line 
      x = x + 1;      // Add 1 to x
      if (x > 100) {  // If x is greater than 100,
        x = -40;      // assign -40 to x
      }
    }
 
 */