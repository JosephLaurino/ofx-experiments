//
//  processing.cpp -- see https://processing.org/reference/ for Processing API documentation
//
//  I got the book Processing Handbook, 2nd Edition as a secret santa gift and I've been meaning to
//  learn Processing.  I also want to learn OpenFrameworks.
//
//  Why not learn both?
//
//  So this is my attept of implementing the Processing API as I encounter them in reading the
//  Processing Handbook
//
//  -Joseph Laurino (5/22/16)

#include "processing.hpp"

namespace processing
{
    float   m_pi = 3.14159265358979f;

    bool    m_inSetup = true; // set to true when resetDrawSettings() is called
    
    ofColor m_defaultFillColor = ofColor(255);
    ofColor m_defaultStrokeColor = ofColor(0);
    float   m_defaultStrokeWeight  = 1.0f;
    bool    m_defaultHasFill = true;
    bool    m_defaultHasStroke = true;
    
    ofColor m_fillColor = ofColor(255);
    ofColor m_strokeColor = ofColor(0);
    float   m_strokeWeight  = 1.0f;
    bool    m_hasFill = true;
    bool    m_hasStroke = true;
    int     width = 100;
    int     height = 100;
    int     pmouseX = 0;
    int     pmouseY = 0;
    bool    mousePressed = false;
    bool    keyPressed = false;
    MouseButton mouseButton = NONE;
    
    ofTrueTypeFont  m_currentTextFont;
    float           m_textSize = 14.0f;
    
    
    void size( int width, int height )
    {
        ofSetWindowShape(width, height);
        width = ofGetWidth();
        height = ofGetHeight();
    }
    
    void background(int rgb)
    {
        if( rgb > 255 )
            ofBackgroundHex(rgb);
        else
            ofBackground(rgb);
        
        ofSetBackgroundAuto(true);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    }
    
    void background(float v1, float v2, float v3)
    {
        ofBackground(ofColor(v1,v2,v3));
        ofSetBackgroundAuto(true);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    }
    
    void cursor()
    {
        ofShowCursor();
    }
    
    void noCursor()
    {
        ofHideCursor();
    }
    
    void frameRate(float fps)
    {
        ofSetFrameRate(fps);
    }
    
    void noFill()
    {
        m_hasFill = false;
        if( m_inSetup )
            m_defaultHasFill = false;
    }
    
    void noStroke()
    {
        m_hasStroke = false;
        if( m_inSetup )
            m_defaultHasStroke = false;
    }
    
    void smooth(int level)
    {
        ofEnableAntiAliasing();
    }
    
    void noSmooth()
    {
        ofDisableAntiAliasing();
    }
    
    void fill(int rgb, float alpha)
    {
        m_hasFill = true;
        if( rgb > 255 )
            m_fillColor.setHex(rgb, alpha);
        else
            m_fillColor.set(rgb, alpha);
        
        ofSetColor(m_fillColor);
        
        if( m_inSetup )
            m_defaultFillColor = m_fillColor;
    }
    
    void fill(float gray, float alpha)
    {
        m_hasFill = true;
        m_fillColor.set(gray,alpha);
        
        ofSetColor(m_fillColor);
        
        if( m_inSetup )
            m_defaultFillColor = m_fillColor;
    }
    
    void fill(double gray, float alpha)
    {
        m_hasFill = true;
        m_fillColor.set(gray,alpha);
        
        ofSetColor(m_fillColor);
        
        if( m_inSetup )
            m_defaultFillColor = m_fillColor;
    }
    
    void fill(int v1, int v2, int v3, float alpha)
    {
        m_hasFill = true;
        m_fillColor = ofColor(v1,v2,v3, alpha);
        
        ofSetColor(m_fillColor);
        
        if( m_inSetup )
            m_defaultFillColor = m_fillColor;
    }
    
    void fill(float v1, float v2, float v3, float alpha)
    {
        m_hasFill = true;
        m_fillColor = ofColor(v1,v2,v3, alpha);
        
        ofSetColor(m_fillColor);
        
        if( m_inSetup )
            m_defaultFillColor = m_fillColor;
    }
    
    void stroke(int rgb, float alpha)
    {
        if( rgb > 255 )
            m_strokeColor.setHex(rgb, alpha);
        else
            m_strokeColor.set(rgb, alpha);
        
        m_hasStroke = true;
        
        if( m_inSetup )
            m_defaultStrokeColor = m_strokeColor;
    }
    
    void stroke(float gray, float alpha)
    {
        m_strokeColor.set(gray, gray, gray, alpha);
        m_hasStroke = true;
        
        if( m_inSetup )
            m_defaultStrokeColor = m_strokeColor;
    }
    
    void stroke(double gray, float alpha)
    {
        m_strokeColor.set(gray, gray, gray, alpha);
        m_hasStroke = true;
        
        if( m_inSetup )
            m_defaultStrokeColor = m_strokeColor;
    }
    
    void stroke(int v1, int v2, int v3, float alpha)
    {
        m_strokeColor = ofColor(v1,v2,v3,alpha);
        m_hasStroke = true;
        
        if( m_inSetup )
            m_defaultStrokeColor = m_strokeColor;
    }
    
    void stroke(float v1, float v2, float v3, float alpha)
    {
        m_strokeColor = ofColor(v1,v2,v3,alpha);
        m_hasStroke = true;
        
        if( m_inSetup )
            m_defaultStrokeColor = m_strokeColor;
    }
    
    void strokeWeight(float weight)
    {
        m_strokeWeight = weight;
        ofSetLineWidth(m_strokeWeight);
        
        if( m_inSetup )
            m_defaultStrokeWeight = weight;
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
    
    void point(float x, float y)
    {
        ellipse(x, y, 1, 1);
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
    
    void bezier( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
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
    
    void quad(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4)
    {
        ofPath p = ofPath();
        handlePathDrawStyle(p);
        p.moveTo(x1,y1);
        p.lineTo(x2,y2);
        p.lineTo(x3,y3);
        p.lineTo(x4,y4);
        p.close();
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
        /*
            // drawing ellipse via ofPath generates a rendering bug when
            // rendering the stroke
         
            ofPath p = ofPath();
            handlePathDrawStyle(p);
            p.setCircleResolution(100);
            p.ellipse(x,y,width,height);
            p.draw();
         
         */
        
        if(m_hasFill)
        {
            ofFill();
            ofSetColor(m_fillColor); //fill color
            ofDrawEllipse(x,y,width,height);
        }
        if( m_hasStroke )
        {
            ofNoFill();
            ofSetColor(m_strokeColor);//stroke color
            ofDrawEllipse(x,y,width,height);
        }
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
    
    void handleDefaultTextFont(float size)
    {
        if( m_currentTextFont.isLoaded() == false )
        {
            m_currentTextFont.load("verdana.ttf", size, true, true);
        }
        else if( m_currentTextFont.getSize() != size)
        {
            m_currentTextFont.load("verdana.ttf", size, true, true);
        }
    }
    
    void text(string textString, float x, float y)
    {
        handleDefaultTextFont(m_textSize);
        m_currentTextFont.drawString(textString, x, y);
    }
    
    void text(char c, float x, float y)
    {
        string txt;
        txt.push_back(c);
        text(txt, x, y);
    }
    
    void textSize(float size)
    {
        m_textSize = size;
        
        handleDefaultTextFont(size);
    }
    
    float map(float value, float istart, float istop, float ostart, float ostop)
    {
        return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
    }
    
    void println(int num)
    {
        string numAsString = to_string(num);
        println(numAsString);
    }
    
    void println(float num)
    {
        string numAsString = to_string(num);
        println(numAsString);
    }

    void println(string str)
    {
        ofLog() << str;
    }
    
    void resetDrawSettings()
    {
        m_inSetup = false;
        
        // processing resets these settings before each draw method
        // so to mimic processing, call this function at the top of the
        // draw method
        fill(m_defaultFillColor.getHex());
        stroke(m_defaultStrokeColor.getHex());
        strokeWeight(m_defaultStrokeWeight);
        m_hasFill = m_defaultHasFill;
        m_hasStroke = m_defaultHasStroke;
        smooth(2);
        
        if( m_hasFill )
        {
            ofSetColor(m_defaultFillColor);
            ofFill();
        }
        
        // store variables for use in draw method
        width = ofGetWidth();
        height = ofGetHeight();
        pmouseX = ofGetPreviousMouseX();
        pmouseY = ofGetPreviousMouseY();
        keyPressed = ofGetKeyPressed();
        mousePressed = ofGetMousePressed();
        mouseButton = NONE;
        
        if( ofGetMousePressed(0) )
            mouseButton = LEFT;
        else if(ofGetMousePressed(1))
            mouseButton = RIGHT;
        
        // in processing, unless background() is called within the draw method
        // the current background is not cleared!
        ofSetBackgroundAuto(false);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        // let's have great looking graphics, openFrameworks default is 20 
        ofSetCircleResolution(100);
        ofSetCurveResolution(100);
    }
    
}
