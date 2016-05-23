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
    void background(float v1, float v2, float v3);
    void noFill();
    void noStroke();
    void smooth(int level);
    void noSmooth();
    void fill(int rgb);
    void fill(float gray);
    void fill(int v1, int v2, int v3, float alpha = 255.0f);
    void fill(float v1, float v2, float v3, float alpha = 255.0f);
    void stroke(int rgb, float alpha = 255.0f);
    void stroke(float gray, float alpha = 255.0f);
    void stroke(int v1, int v2, int v3, float alpha = 255.0f);
    void stroke(float v1, float v2, float v3, float alpha = 255.0f);
    void strokeWeight(float weight);
    void blendMode(BlendMode mode);
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    void rect( float x, float y, float width, float height );
    float bezier( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    void line( float x1, float y1, float x2, float y2);
    void ellipse(float x,float y, float width, float height);
    void arc(float x, float y, float width, float height, float start, float stop );
    void resetDrawSettings(); // call this at the top of the draw() method
}


#endif /* processing_hpp */
