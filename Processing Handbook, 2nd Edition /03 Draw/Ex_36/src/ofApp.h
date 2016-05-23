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
        background(255);
        noStroke();
        fill(242, 204, 47, 160);   // Yellow
        ellipse(47, 36, 64, 64);
        fill(174, 221, 60, 160);   // Green
        ellipse(90, 47, 64, 64);
        fill(116, 193, 206, 160);  // Blue
        ellipse(57, 79, 64, 64);
    }
};
