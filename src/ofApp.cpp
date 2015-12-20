#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
	ofBackground(0, 109, 0);
	
	treeGreen.set(0, 109, 0);
	
	// Syphon setup
	configureSyphon();
	
	mio.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (sceneFlag) {
		ofBackground(0);
		mio.update();
	}
	else {
		if (potsuSetuped == false) {
			ofBackground(0, 109, 0);
			potsu.setup();
			potsuSetuped = true;
		}
		potsu.update();
	}
	
	if (time > 120) {
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
