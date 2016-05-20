#pragma once

#include "ofMain.h"
#include <memory>       // for std::shared_ptr and std::make_shared

using namespace std;    // so that we don't have to type std::

class ofApp : public ofBaseApp
{
    class Diagonals
    {
        int x, y, speed, thick, gray;
        
    public:
        Diagonals(int xpos, int ypos, int s, int t, int g) {
            x = xpos;
            y = ypos;
            speed = s;
            thick = t;
            gray = g;
        }
        
        void update() {
            ofSetLineWidth(thick);
            ofSetColor(gray);
            ofDrawLine(x, y, x+20, y-40);
            ofDrawLine(x+10, y, x+30, y-40);
            ofDrawLine(x+20, y, x+40, y-40);
            x = x + speed;
            if (x > 100) {
                x = -100;
            }
        }
    };

    shared_ptr<Diagonals> da, db;  // http://en.cppreference.com/w/cpp/memory/shared_ptr
    
public:
    void setup()
    {
        ofSetColor(0, 0, 0);
        // Inputs: x, y, speed, thick, gray
        da = make_shared<Diagonals>(0, 80, 1, 2, 0);  // http://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared
        db = make_shared<Diagonals>(0, 55, 2, 6, 255);
    }
    void draw()
    {
        ofBackground(204);
        da->update(); // make sure Diagonals::update method is public
        db->update();
    }
};




/*
 
    Diagonals da, db;

    void setup() {
      size(100, 100);

      // Inputs: x, y, speed, thick, gray
      da = new Diagonals(0, 80, 1, 2, 0);
      db = new Diagonals(0, 55, 2, 6, 255);
    }

    void draw() {
      background(204);
      da.update();
      db.update();
    }

    class Diagonals {
      int x, y, speed, thick, gray;
      
      Diagonals(int xpos, int ypos, int s, int t, int g) {
        x = xpos;
        y = ypos;
        speed = s;
        thick = t;
        gray = g;
      }
      
      void update() {
        strokeWeight(thick);
        stroke(gray);
        line(x, y, x+20, y-40);
        line(x+10, y, x+30, y-40);
        line(x+20, y, x+40, y-40);
        x = x + speed;
        if (x > 100) {
          x = -100;
        }
      }
    }
 
 */