#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include <memory>

using namespace std;

//--------------------------------------------------------------
class FaceTrackingComp : public ofBaseApp
{
    ofImage             img;
    ofxCvHaarFinder     finder;         // facedetect
    ofVideoGrabber      vidGrabber;     // camera video feed
    int                 camWidth;
    int                 camHeight;

public:
    void setup()
    {
        finder.setup("haarcascade_frontalface_default.xml");
        
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
    
    void update()
    {
        if( vidGrabber.isInitialized())
        {
            ofBackground(100, 100, 100);
            vidGrabber.update();
            
            if(vidGrabber.isFrameNew())
            {
                ofPixels& pixels = vidGrabber.getPixels();
                img.setFromPixels(pixels);
                finder.findHaarObjects(img);
            }
        }
    }
    
    void draw()
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
};

//--------------------------------------------------------------
class AudioInputComp : public ofBaseApp
{
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    int     historyMaxSize = 400;
    
    float   smoothedVol;
    float   scaledVol;
    
    ofSoundStream soundStream;
    
public:
    
    void setup(){
        
        ofSetVerticalSync(true);
        ofSetCircleResolution(100);
        ofBackground(54, 54, 54);	
        
        // 0 output channels, 
        // 2 input channels
        // 44100 samples per second
        // 256 samples per buffer
        // 4 num buffers (latency)
        
        soundStream.printDeviceList();
        
        //if you want to set a different device id 
        //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
        
        int bufferSize = 256;
        
        
        left.assign(bufferSize, 0.0);
        right.assign(bufferSize, 0.0);
        volHistory.assign(historyMaxSize, 0.0);
        
        bufferCounter	= 0;
        drawCounter		= 0;
        smoothedVol     = 0.0;
        scaledVol		= 0.0;

        soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

    }

    void update()
    {
        //lets scale the vol up to a 0-1 range 
        scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

        //lets record the volume into an array
        volHistory.push_back( scaledVol );
        
        //if we are bigger the the size we want to record - lets drop the oldest value
        if( volHistory.size() >= historyMaxSize ){
            volHistory.erase(volHistory.begin(), volHistory.begin()+1);
        }
    }

    void draw()
    {
        ofSetColor(225);
        ofNoFill();
        
        // draw the average volume:
        ofPushStyle();
            ofPushMatrix();
            ofTranslate(0, 80, 0);
        
            ofSetColor(245, 58, 135);
            ofFill();
            ofDrawCircle(500, 400, scaledVol * 190.0f);
        
            //lets draw the volume history as a graph
            ofBeginShape();
            for (unsigned int i = 0; i < volHistory.size(); i++)
            {
                if( i == 0 )
                    ofVertex(i, historyMaxSize);

                ofVertex(i, historyMaxSize - volHistory[i] * 400);
                
                if( i == volHistory.size() -1 )
                    ofVertex(i, historyMaxSize);
            }
            ofEndShape(false);		
                
            ofPopMatrix();
        ofPopStyle();
        
        drawCounter++;
        
        ofSetColor(225);
        string reportString = "buffers received: "+ofToString(bufferCounter)+
                              "\ndraw routines called: "+ofToString(drawCounter)+
                              "\nticks: " + ofToString(soundStream.getTickCount());
        
        // ofDrawBitmapString(reportString, 32, 200);
            
    }

    void audioIn(float * input, int bufferSize, int nChannels)
    {
        float curVol = 0.0;
        
        // samples are "interleaved"
        int numCounted = 0;	

        //lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
        for (int i = 0; i < bufferSize; i++){
            left[i]		= input[i*2]*0.5;
            right[i]	= input[i*2+1]*0.5;

            curVol += left[i] * left[i];
            curVol += right[i] * right[i];
            numCounted+=2;
        }
        
        //this is how we get the mean of rms :) 
        curVol /= (float)numCounted;
        
        // this is how we get the root of rms :) 
        curVol = sqrt( curVol );
        
        smoothedVol *= 0.93;
        smoothedVol += 0.07 * curVol;
        
        bufferCounter++;
        
    }

};

//--------------------------------------------------------------
class ofApp : public ofBaseApp
{
    shared_ptr<FaceTrackingComp> faceTrackingComp;
    shared_ptr<AudioInputComp>   audioInputComp;
    
public:
    
    void setup()
    {
        faceTrackingComp = make_shared<FaceTrackingComp>();
        faceTrackingComp->setup();
        
        audioInputComp = make_shared<AudioInputComp>();
        audioInputComp->setup();
    }

    void update()
    {
        faceTrackingComp->update();
        audioInputComp->update();
    }
    
    void draw()
    {
        faceTrackingComp->draw();
        audioInputComp->draw();
    }
};
