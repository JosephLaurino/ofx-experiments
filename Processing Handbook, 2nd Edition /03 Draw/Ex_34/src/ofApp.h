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

        background(0);
        fill(255, 220);  // High opacity
        rect(15, 15, 50, 50);
        rect(35, 35, 50, 50);
    }
};

