#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "Mio01.h"
#include "Potsu.h"

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
		Potsu potsu;
		bool sceneFlag = true;
		bool changedFlag = false;
		bool potsuSetuped = false;
		int time = 0;
	
	private:
		void configureSyphon();
		void sendToSyphonServer();
	
};
