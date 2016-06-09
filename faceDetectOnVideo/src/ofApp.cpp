#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    finder.setup("haarcascade_frontalface_default.xml");
    finder.findHaarObjects(img);
    
    // video
    camWidth = 640;
    camHeight = 480;
    
    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    if( devices.size() > 0 )
    {
        vidGrabber.setDeviceID(0);
        vidGrabber.setDesiredFrameRate(60);
        vidGrabber.initGrabber(camWidth, camHeight);
        
        img.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
        ofSetVerticalSync(true);
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    if( vidGrabber.isInitialized())
    {
        ofBackground(100, 100, 100);
        vidGrabber.update();
        
        if(vidGrabber.isFrameNew())
        {
            ofPixels & pixels = vidGrabber.getPixels();
            img.setFromPixels(pixels);
            finder.findHaarObjects(img);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    if( vidGrabber.isInitialized())
    {
        img.draw(0, 0);
        ofNoFill();
        for(unsigned int i = 0; i < finder.blobs.size(); i++) {
            ofRectangle cur = finder.blobs[i].boundingRect;
            ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
