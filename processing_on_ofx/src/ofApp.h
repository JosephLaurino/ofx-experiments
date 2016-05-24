#pragma once

#include "processing.hpp"   // for processing api

using namespace processing; // so that we don't have to type processing::

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        size(100, 100);
        noStroke();
    }
    
    void draw()
    {
        processing::resetDrawSettings();
        
        float x = mouseX;
        float y = mouseY;
        float ix = width - mouseX;   // Inverse X
        float iy = height - mouseY;  // Inverse Y
        
        background(126);
        fill(255, 150);
        ellipse(x, height/2, y, y);
        fill(0, 159);
        ellipse(ix, height/2, iy, iy);
    }
};

