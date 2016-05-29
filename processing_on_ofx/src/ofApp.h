#pragma once

#include "processing.hpp"   // for processing api

using namespace processing; // so that we don't have to type processing::

class ofApp : public ofBaseApp
{
    char key = 0;
    int gray = 0;
    
public:
    
#if 0
    
    // -----------------------------
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
    
    // -----------------------------
    
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

    // -----------------------------
    
    void setup() {
        size(100, 100);
        fill(0, 102);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
    }

    // -----------------------------
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
    
    // -----------------------------
    
    
    void setup() {
        size(100, 100);
        strokeWeight(7);
        noCursor();
    }
    
    void draw() {
        processing::resetDrawSettings();
        background(204);
        ellipse(mouseX, mouseY, 10, 10);
    }
    
    void keyPressed(int _key)
    {
        key = _key;
    }
    
    // -----------------------------
    
    void draw()
    {
                int x = -16;
        while (x < 100) {
            line(x, 0, x+15, 50);
            x += 10;
        }
        strokeWeight(4);
        x = -8;
        while (x < 100) {
            line(x, 50, x+15, 100); 
            x += 10;
        }
    }
    
    // -----------------------------

    
    void setup() {
        size(100, 100);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
        
        noFill();
        for (int d = 150; d > 0; d -= 10) {
            ellipse(50, 50, d, d);
        }
    }
 
    // -----------------------------
    
    void setup() {
        size(100, 100);
    }
    
    void draw()
    {
        background(255);
        strokeWeight(2);
        for (int i = 0; i < 100; i += 4) {
            // The variable is used for the position and gray value
            stroke((float)(i*2.5));
            line(i, 0, i, 200); 
        }
    }
    
    // -----------------------------
    
    void setup()
    {
        // Halves a number 10 times
        float num = 20;
        for (int i = 0; i < 10; i++) {
            num = num / 2.0;
            println(num);
        }
    }
    
    // -----------------------------
    
    void setup() {
        size(100, 100);
        strokeWeight(2);
    }
    
    void draw() {
        processing::resetDrawSettings();
        background(204);
        // Draw more lines as mouseX increases
        for (int i = 10; i < mouseX; i+=5) {
            line(i, 10, i, 90);
        }
    }
    
    // -----------------------------
    int x = 0;
    
    void setup() {
        size(100, 100);
    }
    
    void draw() {
        processing::resetDrawSettings();
        
        // The variable y iterates from 10 to 90 to draw
        // the point 9 times and the variable x iterates from
        // 10 to 90 to draw the point 81 times
        for (int y = 10; y < 100; y += 10) {
            for (int x = 10; x < 100; x += 10) {
                point(x, y);
            }
        }
    }
    
    // -----------------------------
    void setup() {
        size(100, 100);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
        fill(0);
        noStroke();
        for (int y = -10; y <= 100; y += 10) {
            for (int x = -40; x <= 100; x += 10) {
                ellipse(x + y/3.0, y + x/8.0, 4, 7);
            }
        }
    }
    
    // -----------------------------
    void setup() {
        size(100, 100);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
        noStroke();
        for (int y = 0; y < 100; y += 10) {
            for (int x = 0; x < 100; x += 10) {
                fill((x+y) * 1.4);
                rect(x, y, 10, 10);
            }
        }
    }
    
    
    // -----------------------------
    void setup() {
        size(100, 100);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
        for (int y = 1; y < 100; y += 10) {
            for (int x = 1; x < y; x += 10) {
                line(x, y, x+6, y+6);
                line(x+6, y, x, y+6);
            }
        }
    }
    
    // -----------------------------
    void setup() {
        size(100, 100);
    }
    
    void draw()
    {
        // rectMode(CENTER);
        for (int d = 18; d > 0; d -= 4) {
            rect(50, 50, d, d);
        }
    }
    
    // -----------------------------
    void setup() {
        size(600, 600);
    }
    
    void draw() {
        processing::resetDrawSettings();
        
        background(0);
        stroke(102);
        line(0, height/2, width, height/2);
        noStroke();
        fill(255, 204);
        int d = mouseY/2+10; // Diameter
        ellipse(mouseX, height/2, d, d);
        fill(255, 204);
        int iX = width-mouseX;   // Inverse X
        int iY = height-mouseY;  // Inverse Y
        int iD = (iY/2)+10;  // Inverse diameter
        ellipse(iX, height/2, iD, iD);
    }
    
    // -----------------------------
    void setup() {
        size(600, 600);
        strokeWeight(2);
        noCursor();
    }
    
    void draw() {
        processing::resetDrawSettings();
        background(102);
        
        noStroke();
        fill(0);
        rect(150, 150, 300, 300);
        
        stroke(255);
        if ((mouseX > 150) && (mouseX < 450) &&
            (mouseY > 150) && (mouseY < 450)) {
            line(0, 0, 150, 150);      // Upper-left
            line(600, 0, 450, 150);    // Upper-right
            line(450, 450, 600, 600);  // Lower-right
            line(0, 600, 150, 450);    // Lower-left
        } else {
            line(150, 150, 450, 450);  // Upper-left to lower-right
            line(150, 450, 450, 150);  // Lower-left to upper-right
        }
        
        noStroke();
        fill(0);
        ellipse(mouseX, mouseY, 12, 12);
    }
    
    // -----------------------------
    int gap = 20;  // Distance between arcs
    int thickness = 2;  // Thickness of each arc
    
    void setup() {
        size(600, 600);
        noFill();
        strokeWeight(thickness);
        stroke(0);
    }
    
    void draw() {
        processing::resetDrawSettings();
        background(255);
        float arcLength = mouseX / 95.0;
        for (int i = gap; i < width-gap; i += gap) {
            float angle = radians(i);
            arc(width/2, height/2, i, i, angle, angle + arcLength);
        }
    }
    
    // -----------------------------
    
    int mode = 1;
    int lastMode = 3;
    
    void setup() {
        size(600, 600);
    }
    
    void draw() {
        processing::resetDrawSettings();
        background(204);
        if (mode == 1) {
            // Based on code TC
            fill(0);
            noStroke();
            ellipse(210, 0, 720, 720);
            ellipse(228, 377, 36, 36);
            ellipse(240, 605, 420, 420);
        } else if (mode == 2) {
            // Based on code TC
            stroke(0);
            strokeWeight(2);
            fill(255);
            rect(60, 60, 300, 300);
            noFill();
            rect(120, 120, 360, 360);
            rect(180, 180, 360, 360);
        } else {
            // Based on code TC
            stroke(0);
            strokeWeight(10);
            for (int y = 120; y < 480; y += 30) {
                line(120, y, 480, y + 90); 
            }
        }
    }
    
    void mousePressed(int x, int y, int button) {
        mode++;
        if (mode > lastMode) {
            mode = 1; 
        }
    }
    
#endif
    
    // -----------------------------
    void setup()
    {
        size(100,100);
    }
    
    void draw()
    {
        processing::resetDrawSettings();
        
        textSize(32);
        fill(0);    // Fill color black
        text("LAX", 0, 40);
        fill(126);  // Fill color gray
        text("HKG", 0, 70);
        fill(255);  // Fill color white
        text("PVG", 0, 100);

    }
    
};

