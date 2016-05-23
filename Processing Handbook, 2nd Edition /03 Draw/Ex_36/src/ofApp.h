#pragma once

#include "processing.hpp"   // for processing api

using namespace processing; // so that we don't have to type processing::

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        size(100,100);
    }
    void draw()
    {
        processing::resetDrawFlags();
/*
        
        rect(10, 10, 50, 50);
        noFill();  // Disable the fill
        rect(20, 20, 50, 50);
        rect(30, 30, 50, 50);
  */
        stroke(153.0f, 204);
        strokeWeight(12);
        background(0);
        line(20, 20, 40, 80);
        line(40, 20, 20, 80);
        blendMode(ADD);  // Change blend mode
        line(60, 20, 80, 80);
        line(80, 20, 60, 80);
    }
};
