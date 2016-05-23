#pragma once

#include "ofMain.h"
#include <memory>       // for std::shared_ptr and std::make_shared

using namespace std;    // so that we don't have to type std::

namespace processing
{
    float   m_pi = 3.14159265358979f;
    ofColor m_fillColor = ofColor(255);
    ofColor m_strokeColor = ofColor(255);
    float   m_strokeWeight  = 1.0f;

    
    static void size( int width, int height )
    {
        ofSetWindowShape(100, 100);
    }
    
    static void background(ofColor color)
    {
        ofBackground(color);
    }
    
    static void fill(ofColor color)
    {
        ofSetColor(color);
        m_fillColor = color;
    }
    
    static void stroke(ofColor color)
    {
        m_strokeColor = color;
    }
    
    static void strokeWeight(float weight)
    {
        m_strokeWeight = weight;
    }

    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    static float radians(float deg)
    {
        return deg * m_pi / 180.0f;
    }
    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    static float degrees( float rad )
    {
        return rad * 180.0f / m_pi;
    }

    static void rect( float x, float y, float width, float height )
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.moveTo(x, y);
        p.lineTo(x+width, y);
        p.lineTo(x+width, y+height);
        p.lineTo(x, y+height);
        p.close();
        p.draw();
    }
    
    static float bezier( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.moveTo(ofPoint(x1, y1));
        p.bezierTo(ofPoint(x2, y2), ofPoint(x3, y3), ofPoint(x4, y4));
        p.draw();
    }
    
    // x1	float: x-coordinate of the first point
    // y1	float: y-coordinate of the first point
    // x2	float: x-coordinate of the second point
    // y2	float: y-coordinate of the second point
    static void line( float x1, float y1, float x2, float y2)
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.moveTo(x1, y1);
        p.lineTo(x2, y2);
        p.draw();
    }
    
    // float: x-coordinate of the ellipse
    // float: y-coordinate of the ellipse
    // float: width of the ellipse by default
    // float: height of the ellipse by default
    static void ellipse(float x,float y, float width, float height)
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.ellipse(x,y,width,height);
        p.draw();
    }
    
    // x      float: x-coordinate of the arc's ellipse
    // y      float: y-coordinate of the arc's ellipse
    // width  float: width of the arc's ellipse by default
    // height float: height of the arc's ellipse by default
    // start  float: angle to start the arc, specified in radians
    // stop   float: angle to stop the arc, specified in radians
    static void arc(float x, float y, float width, float height, float start, float stop )
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.arc(x,y,width*.5,height*.5, degrees(start), degrees(stop));
        p.close();
        p.draw();
    }
    
    void draw()
    {
        fill(255);
        stroke(0);
        //processingDraw();
    }
    
}

using namespace processing;



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
};


class ofApp : public ofBaseApp
{
    shared_ptr<Diagonals> da, db;  // http://en.cppreference.com/w/cpp/memory/shared_ptr
    
public:
    void setup()
    {
        size(100,100);
        // Inputs: x, y, speed, thick, gray
        da = make_shared<Diagonals>(0, 80, 1, 2, 0);  // http://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared
        db = make_shared<Diagonals>(0, 55, 2, 6, 255);
    }
    void draw()
    {
        processing::draw();
        background(204);
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