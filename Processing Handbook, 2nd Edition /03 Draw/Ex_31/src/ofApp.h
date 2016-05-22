#pragma once

#include "ofMain.h"

class processingApp : public ofBaseApp
{
public:

    void size( int width, int height )
    {
        ofSetWindowShape(100, 100);
    }
    
    void background(ofColor color)
    {
        ofBackground(color);
    }
    
    void fill(ofColor color)
    {
        ofSetColor(color);
        m_fillColor = color;
    }
    
    void rect( float x, float y, float width, float height )
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.moveTo(x, y);
        p.lineTo(x+width, y);
        p.lineTo(x+width, y+height);
        p.lineTo(x, y+height);
        p.close();
        p.draw();
    }
    
    float bezier( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.moveTo(ofPoint(x1, y1));
        p.bezierTo(ofPoint(x2, y2), ofPoint(x3, y3), ofPoint(x4, y4));
        p.draw();
    }
    
    // x1	float: x-coordinate of the first point
    // y1	float: y-coordinate of the first point
    // x2	float: x-coordinate of the second point
    // y2	float: y-coordinate of the second point
    void line( float x1, float y1, float x2, float y2)
    {
        ofDrawLine(x1, y1, x2, y2);
    }
    
    // float: x-coordinate of the ellipse
    // float: y-coordinate of the ellipse
    // float: width of the ellipse by default
    // float: height of the ellipse by default
    void ellipse(float x,float y, float width, float height)
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.ellipse(x,y,width,height);
        p.draw();
    }
    
    // x      float: x-coordinate of the arc's ellipse
    // y      float: y-coordinate of the arc's ellipse
    // width  float: width of the arc's ellipse by default
    // height float: height of the arc's ellipse by default
    // start  float: angle to start the arc, specified in radians
    // stop   float: angle to stop the arc, specified in radians
    void arc(float x, float y, float width, float height, float start, float stop )
    {
        ofPath p = ofPath();
        p.setColor(m_fillColor);
        p.setStrokeColor(ofColor(0, 0, 0));
        p.setStrokeWidth(1);
        p.arc(x,y,width*.5,height*.5, degrees(start), degrees(stop));
        p.close();
        p.draw();
    }
    
    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    float radians(float deg)
    {
        return deg * m_pi / 180.0f;
    }
    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    float degrees( float rad )
    {
        return rad * 180.0f / m_pi;
    }
    
private:
    const float  m_pi = 3.14159265358979f;
    ofColor m_fillColor;
    
};


class ofApp : public processingApp
{
public:
    void setup()
    {
        size(100, 100);
    }
    
    void draw()
    {
        rect(10, 10, 50, 50);
        fill(204);  // Light gray
        rect(20, 20, 50, 50);
        fill(153);  // Middle gray
        rect(30, 30, 50, 50);
        fill(102);  // Dark gray
        rect(40, 40, 50, 50);
    }
};


/*
 
 // reference Processing code
 
 rect(10, 10, 50, 50);
 fill(204);  // Light gray
 rect(20, 20, 50, 50);
 fill(153);  // Middle gray
 rect(30, 30, 50, 50);
 fill(102);  // Dark gray
 rect(40, 40, 50, 50);
 
 */