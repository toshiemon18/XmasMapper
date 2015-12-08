#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofEnableSmoothing();
	
	ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	drawBaseTree();
}

void ofApp::drawBaseTree() {
	ofSetColor(0, 255, 0);
	ofBeginShape();
		ofVertex(ofGetWidth() / 2.0, 0);
	
		ofVertex((1 / 3.0) * ofGetWidth(), (1 / 3.0) * (ofGetHeight() - 100)); // A
		ofVertex((1 / 3.0) * ofGetWidth() + 25, (1 / 3.0) * (ofGetHeight() - 100)); // C
	
		ofVertex((1 / 6.0) * ofGetWidth(), (2 / 3.0) * (ofGetHeight() - 100)); // E
		ofVertex((1 / 6.0) * ofGetWidth() + 50, (2 / 3.0) * (ofGetHeight() - 100)); // G
	
		ofVertex(0, ofGetHeight()); // I
		ofVertex(ofGetWidth(), ofGetHeight()); // J
	
		ofVertex((5 / 6.0) * ofGetWidth() - 50, (2 / 3.0) * (ofGetHeight() - 100)); // H
		ofVertex((5 / 6.0) * ofGetWidth(), (2 / 3.0) * (ofGetHeight() - 100)); // F
	
		ofVertex((2 / 3.0) * ofGetWidth() - 25, (1 / 3.0) * (ofGetHeight() - 100)); //D
		ofVertex((2 / 3.0) * ofGetWidth(), (1 / 3.0) * (ofGetHeight() - 100)); // B
	ofEndShape();
}
