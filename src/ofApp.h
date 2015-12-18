#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "Mio01.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofColor treeGreen;
	
		// using ofxSyphon
		ofxSyphonServer mainOutputSyphonServer;
		ofxSyphonServer individualTextureSyphonServer;
		ofxSyphonClient mClient;
	
		Mio01 mio;

	
	private:
		void drawBaseTree();
		void configureSyphon();
		void sendToSyphonServer();
	
};
