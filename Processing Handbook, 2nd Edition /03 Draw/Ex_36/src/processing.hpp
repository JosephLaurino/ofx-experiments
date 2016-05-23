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
    enum BlendMode
    {
        BLEND,      // - linear interpolation of colours: C = A*factor + B. This is the default blending mode.
        ADD,        // - additive blending with white clip: C = min(A*factor + B, 255)
        SUBTRACT,   // - subtractive blending with black clip: C = max(B - A*factor, 0
        DARKEST,    // - only the darkest colour succeeds: C = min(A*factor, B)
        LIGHTEST,   // - only the lightest colour succeeds: C = max(A*factor, B)
        DIFFERENCE, // - subtract colors from underlying image.
        EXCLUSION,  // - similar to DIFFERENCE, but less extreme.
        MULTIPLY,   // - multiply the colors, result will always be darker.
        SCREEN,     // - opposite multiply, uses inverse values of the colors.
        REPLACE     // - the pixels entirely replace the others and don't utilize alpha (transparency) values
    };
    
    // math
    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    float radians(float deg);
    // http://www.teacherschoice.com.au/maths_library/angles/angles.htm
    float degrees( float rad );
    
    // graphics
    void size( int width, int height );
    void background(int rgb);
    void background(ofColor color);
    void background(float v1, float v2, float v3);
    void noFill();
    void noStroke();
    void fill(int rgb);
    void fill(float gray);
    void fill(float v1, float v2, float v3, float alpha = 255.0f);
    void fill(ofColor color, float alpha);
    void stroke(int rgb, float alpha = 255.0f);
    void stroke(float gray, float alpha = 255.0f);
    void stroke(ofColor color);
    void stroke(float v1, float v2, float v3, float alpha = 255.0f);
    void strokeWeight(float weight);
    void blendMode(BlendMode mode);
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
