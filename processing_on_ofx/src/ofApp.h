#pragma once

#include "processing.hpp"   // for processing api

using namespace processing; // so that we don't have to type processing::

class ofApp : public ofBaseApp
{
    char key = 0;
    int gray = 0;
    
public:
    
#if 0
    void setup()
    {
        size(100, 100);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
        
        float x = mouseX;
        float y = mouseY;
        float ix = width - mouseX;   // Inverse X
        float iy = height - mouseY;  // Inverse Y
        
        // background(126);
        fill(255, 150);
        ellipse(x, height/2, y, y);
        fill(0, 159);
        ellipse(ix, height/2, iy, iy);
        
        
    }
    
    void setup()
    {
        size(100, 100);
    }
    
    void draw()
    {
        processing::resetDrawSettings();

        background(0);
        rect(10, 10, 50, 50);
        stroke(102); // Dark gray
        rect(20, 20, 50, 50);
        stroke(153); // Middle gray
        rect(30, 30, 50, 50);
        stroke(204); // Light gray
        rect(40, 40, 50, 50);
    }


    
    void setup() {
        size(100, 100);
        fill(0, 102);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
    }
#endif

    int dragX, dragY, moveX, moveY;
    
    void setup() {
        size(100, 100);
        noStroke();
    }
    
    void draw() {
        processing::resetDrawSettings();
        
        background(204);
        fill(0);
        ellipse(dragX, dragY, 33, 33);  // Black circle
        fill(153);
        ellipse(moveX, moveY, 33, 33);  // Gray circle
    }
    
    void mouseMoved(int x, int y) {    // Move gray circle
        moveX = mouseX;
        moveY = mouseY;
    }
    
    void mouseDragged(int x, int y, int button){  // Move black circle
        dragX = mouseX;
        dragY = mouseY;
    }
    
    void mousePressed(int x, int y, int button)
    {
    }
    
    void keyPressed(int _key)
    {
        key = _key;
    }
    
    
};

