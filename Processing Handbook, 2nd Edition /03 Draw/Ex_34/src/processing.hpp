//
//  processing.hpp
//  Ex_08
//
//  Created by Joseph Laurino on 5/22/16.
//
//

#ifndef processing_hpp
#define processing_hpp

#include "ofMain.h"

namespace processing
{
    // math
    
    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    float radians(float deg);
    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    float degrees( float rad );
    
    // graphics
    void size( int width, int height );
    void background(ofColor color);
    void fill(int rgb);
    void fill(ofColor color, float alpha);
    void stroke(ofColor color);
    void strokeWeight(float weight);
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    void rect( float x, float y, float width, float height );
    float bezier( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    // x1	float: x-coordinate of the first point
    // y1	float: y-coordinate of the first point
    // x2	float: x-coordinate of the second point
    // y2	float: y-coordinate of the second point
    void line( float x1, float y1, float x2, float y2);
    // float: x-coordinate of the ellipse
    // float: y-coordinate of the ellipse
    // float: width of the ellipse by default
    // float: height of the ellipse by default
    void ellipse(float x,float y, float width, float height);
    // x      float: x-coordinate of the arc's ellipse
    // y      float: y-coordinate of the arc's ellipse
    // width  float: width of the arc's ellipse by default
    // height float: height of the arc's ellipse by default
    // start  float: angle to start the arc, specified in radians
    // stop   float: angle to stop the arc, specified in radians
    void arc(float x, float y, float width, float height, float start, float stop );
    void resetDrawFlags();
}


#endif /* processing_hpp */
