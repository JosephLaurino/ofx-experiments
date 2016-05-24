#pragma once

#include "processing.hpp"   // for processing api

using namespace processing; // so that we don't have to type processing::

class ofApp : public ofBaseApp
{
    string key = "";
    float angle = 0;
    
public:
    void setup()
    {
        size(100, 100);
        fill(0);
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
        if (processing::keyPressed == true) {
            if ((key[0] >= 32) && (key[0] <= 126)) {
                // If the key is alphanumeric,
                // convert its value into an angle
                angle = processing::map(key[0], 32, 126, 0, 360);
            }
        } 
        arc(50, 50, 66, 66, 0, radians(angle));
    }
    
    void keyPressed(int _key)
    {
        key.clear();
        key.push_back((char)_key);
    }
};
