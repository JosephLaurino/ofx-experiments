#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    
    // ofAppGlutWindow window;
    // window.setGlutDisplayString("rgba double samples>=4");
    // ofSetupOpenGL(&window, 1024,768, OF_WINDOW);
    
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
