#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofxSyphonServer mainOutputSyphonServer;
		ofxSyphonServer individualTextureSyphonServer;
		ofxSyphonClient mClient;

	
	private:
		void drawBaseTree();
		void configureSyphon();
		void sendToSyphonServer();
	
};
