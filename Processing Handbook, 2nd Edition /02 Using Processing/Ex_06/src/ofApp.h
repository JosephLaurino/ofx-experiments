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
        diagonals(40, 90);
        diagonals(60, 62);
        diagonals(20, 40);
    }
    
    void diagonals(int x, int y) {
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
      diagonals(40, 90);
      diagonals(60, 62);
      diagonals(20, 40);
    }

    void diagonals(int x, int y) {
      line(x, y, x+20, y-40);
      line(x+10, y, x+30, y-40);
      line(x+20, y, x+40, y-40);
    }
 
 */
