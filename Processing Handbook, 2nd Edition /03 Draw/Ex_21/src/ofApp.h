#pragma once


#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
    void setup()
    {
        // ofSetWindowShape(100, 100);
    }
    
    void draw()
    {
        arc(50, 50, 75, 75, radians(40), radians(320));
    }
    
    // float: x-coordinate of the arc's ellipse
    // float: y-coordinate of the arc's ellipse
    // float: width of the arc's ellipse by default
    // float: height of the arc's ellipse by default
    // float: angle to start the arc, specified in radians
    // float: angle to stop the arc, specified in radians
    
    void arc(float x, float y, float width, float height, float start, float stop )
    {
        ofPath p = ofPath();
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
};





/*
 
 // reference Processing code
 
 arc(50, 50, 75, 75, radians(40), radians(320));
 
 */