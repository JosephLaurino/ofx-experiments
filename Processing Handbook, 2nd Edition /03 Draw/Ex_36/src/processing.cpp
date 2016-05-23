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
    bool    m_hasFill = true;
    bool    m_hasStroke = true;
    
    
    void size( int width, int height )
    {
        ofSetWindowShape(100, 100);
    }
    
    void background(int rgb)
    {
        // ofBackgroundHex(rgb);
        ofBackground(rgb);
    }
    
    void background(ofColor color)
    {
        ofBackground(color);
    }
    
    void background(float v1, float v2, float v3)
    {
        ofBackground(ofColor(v1,v2,v3));
    }
    
    void noFill()
    {
        m_hasFill = false;
    }
    
    void noStroke()
    {
        m_hasStroke = false;
    }
    
    void fill(ofColor color)
    {
        m_hasFill = true;
        m_fillColor = color;
    }
    
    void fill(int rgb)
    {
        m_hasFill = true;
        m_fillColor.setHex(rgb);
    }
    
    void fill(float gray)
    {
        m_hasFill = true;
        m_fillColor.set(gray);
    }
    
    void fill(float v1, float v2, float v3, float alpha)
    {
        m_hasFill = true;
        m_fillColor = ofColor(v1,v2,v3, alpha);
    }
    
    void fill(ofColor color, float alpha)
    {
        m_hasFill = true;
        m_fillColor = color;
        m_fillColor.a = alpha;
    }
    
    void stroke(int rgb, float alpha)
    {
        m_strokeColor.setHex(rgb | (int) alpha);
        m_hasStroke = true;
    }
    
    void stroke(float gray, float alpha)
    {
        m_strokeColor.set(gray, gray, gray, alpha);
        m_hasStroke = true;
    }
    
    void stroke(ofColor color)
    {
        m_strokeColor = color;
        m_hasStroke = true;
    }
    
    void stroke(float v1, float v2, float v3, float alpha)
    {
        m_strokeColor = ofColor(v1,v2,v3,alpha);
        m_hasStroke = true;
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
    
    void blendMode(BlendMode mode)
    {
        switch(mode)
        {
            case BLEND:      // - linear interpolation of colours: C = A*factor + B. This is the default blending mode.
                ofEnableBlendMode(OF_BLENDMODE_ALPHA);
                break;
            case ADD:        // - additive blending with white clip: C = min(A*factor + B, 255)
                ofEnableBlendMode(OF_BLENDMODE_ADD);
                break;
            case SUBTRACT:   // - subtractive blending with black clip: C = max(B - A*factor, 0
                ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
                break;
            case DARKEST:    // - only the darkest colour succeeds: C = min(A*factor, B)
                break;
            case LIGHTEST:   // - only the lightest colour succeeds: C = max(A*factor, B)
                break;
            case DIFFERENCE: // - subtract colors from underlying image.
                break;
            case EXCLUSION:  // - similar to DIFFERENCE, but less extreme.
                break;
            case MULTIPLY:   // - multiply the colors, result will always be darker.
                ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
                break;
            case SCREEN:     // - opposite multiply, uses inverse values of the colors.
                ofEnableBlendMode(OF_BLENDMODE_SCREEN);
                break;
            case REPLACE:     // -
                break;
        }
    }
    
    void handlePathDrawStyle(ofPath& p)
    {
        p.setFilled(m_hasFill);
        p.setFillColor(m_fillColor);
        p.setStrokeColor(m_strokeColor);
        if( m_hasStroke )
        {
            p.setStrokeWidth(m_strokeWeight);
        }
        else
        {
            p.setStrokeWidth(0);
        }
    }
    
    void rect( float x, float y, float width, float height )
    {
        ofPath p = ofPath();
        handlePathDrawStyle(p);
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
        handlePathDrawStyle(p);
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
        handlePathDrawStyle(p);
        p.moveTo(x1, y1);
        p.lineTo(x2, y2);
        p.draw();
    }
    
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3)
    {
        ofPath p = ofPath();
        handlePathDrawStyle(p);
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
        handlePathDrawStyle(p);
        p.setCircleResolution(100);
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
        handlePathDrawStyle(p);
        p.setCurveResolution(100);
        p.arc(x,y,width*.5,height*.5, degrees(start), degrees(stop));
        p.close();
        p.draw();
    }
    
    void resetDrawFlags()
    {
        fill(255.0f);
        stroke(0.0f);
        strokeWeight(1);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    }
    
}
