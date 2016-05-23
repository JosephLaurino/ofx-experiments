#pragma once

#include "processing.hpp"   // for processing api

using namespace processing; // so that we don't have to type processing::

class ofApp : public ofBaseApp
{
    float x = 0;
public:
    void setup()
    {
        size(100,100);
    }
    void draw()
    {
        processing::resetDrawSettings();
/*
        rect(10, 10, 50, 50);
        noFill();  // Disable the fill
        rect(20, 20, 50, 50);
        rect(30, 30, 50, 50);
  */
        
        background(204);
        if (x < 80) {
            if (x < 40) {
                ellipse(50, 50, 20, 20);  // Small circle
            } else {
                ellipse(50, 50, 60, 60);  // Large circle
            }
        } else {
            rect(20, 20, 60, 60);
        }
        line(x, 0, x, 100);
        x += 0.25;
        
        
        /*
        noStroke();
        fill(206, 60, 60);
        rect(0, 0, 20, 100);
        fill(186, 89, 60);
        rect(20, 0, 20, 100);
        fill(166, 118, 60);
        rect(40, 0, 20, 100);
        fill(147, 147, 60);
        rect(60, 0, 20, 100);
        fill(108, 206, 60);
        rect(80, 0, 20, 100);*/
    }
};
