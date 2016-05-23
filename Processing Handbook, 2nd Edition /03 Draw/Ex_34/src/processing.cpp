//
//  processing.cpp
//  Ex_08
//
//  Created by Joseph Laurino on 5/22/16.
//
//

#include "processing.hpp"

namespace processing
{
    float   m_pi = 3.14159265358979f;
    ofColor m_fillColor = ofColor(255);
    ofColor m_strokeColor = ofColor(255);
    float   m_strokeWeight  = 1.0f;
    
    
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
        m_fillColor = color;
    }
    
    void fill(int rgb)
    {
        m_fillColor = ofColor(rgb);
    }
    
    void fill(ofColor color, float alpha)
    {
        m_fillColor = color;
        m_fillColor.a = alpha;
    }
    
    void stroke(ofColor color)
    {
        m_strokeColor = color;
    }
    
    void strokeWeight(float weight)
    {
        m_strokeWeight = weight;
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
    
    void rect( float x, float y, float width, float height )
    {
        ofPath p = ofPath();
        p.setFillColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
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
        p.setFillColor(m_fillColor);
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
    void line( float x1, float y1, float x2, float y2)
    {
        ofPath p = ofPath();
        p.setFillColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.moveTo(x1, y1);
        p.lineTo(x2, y2);
        p.draw();
    }
    
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3)
    {
        ofPath p = ofPath();
        p.setFillColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.moveTo(x1, y1);
        p.lineTo(x2, y2);
        p.lineTo(x3, y3);
        p.close();
        p.draw();
    }
    
    // float: x-coordinate of the ellipse
    // float: y-coordinate of the ellipse
    // float: width of the ellipse by default
    // float: height of the ellipse by default
    void ellipse(float x,float y, float width, float height)
    {
        ofPath p = ofPath();
        p.setFillColor(m_fillColor);
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
    void arc(float x, float y, float width, float height, float start, float stop )
    {
        ofPath p = ofPath();
        p.setFillColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        p.setStrokeWidth(m_strokeWeight);
        p.arc(x,y,width*.5,height*.5, degrees(start), degrees(stop));
        p.close();
        p.draw();
    }
    
    void resetDrawFlags()
    {
        fill(255);
        stroke(0);
    }
    
}
