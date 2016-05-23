#include "ofApp.h"

/*
// const float  processingApp::m_pi = 3.14159265358979f;
ofColor processingApp::m_fillColor = ofColor(255);
ofColor processingApp::m_strokeColor = ofColor(255);
float   processingApp::m_strokeWeight  = 1.0f;
*/

// #include "ofApp.h"

//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
}