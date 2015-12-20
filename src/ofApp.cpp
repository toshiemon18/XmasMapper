#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
//	ofBackground(0, 109, 0);
	
	treeGreen.set(0, 109, 0);
	
	// Syphon setup
	configureSyphon();
	
	mio.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (sceneFlag) {
		ofEnableSmoothing();
		ofSetCircleResolution(64);
		ofBackground(0);

		mio.update();
	}
	else {
		if (potsuSetuped == false) {
			ofSetCircleResolution(64);
			ofBackground(0, 109, 0);
			ofEnableAlphaBlending();

			potsu.setup();
			potsuSetuped = true;
		}
		ofSetCircleResolution(64);
		ofBackground(0, 109, 0);
		ofEnableAlphaBlending();

		potsu.update();
	}
	
	if (time > 300) {
		changedFlag = true;
		sceneFlag = !sceneFlag;
		time = 0;
		if (!sceneFlag && !potsuSetuped) {
			
			potsu.setup();
			ofBackground(0, 109, 0);
			potsuSetuped = true;
		}
	}
	time++;
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (sceneFlag) {
		mio.draw();
	}
	else {
		if (potsuSetuped) {
			potsu.draw();
		}
	}
	
	// using Syphon server
	sendToSyphonServer();
}
void ofApp::configureSyphon() {
	mainOutputSyphonServer.setName("Screen Outputh");
	mClient.setup();
	mClient.setApplicationName("Simple Serverh");
	mClient.setServerName("");
}

void ofApp::sendToSyphonServer() {
	mClient.draw(50, 50);
	mainOutputSyphonServer.publishScreen();
}
