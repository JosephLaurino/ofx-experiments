#pragma once

#include "processing.hpp"   // for processing api

using namespace processing; // so that we don't have to type processing::

class ofApp : public ofBaseApp
{
    string key = "";
    
public:
    void setup()
    {
        size(100, 100);
        strokeWeight(4);
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
        // If the 'A' key is pressed draw a line
        if ((processing::keyPressed == true) && (key[0] == 'A')) {
            line(50, 25, 50, 75);
        } else {  // Otherwise, draw an ellipse
            ellipse(50, 50, 50, 50);
        }
    }
    
    void keyPressed(int _key)
    {
        key.clear();
        key.push_back((char)_key);
    }
};
