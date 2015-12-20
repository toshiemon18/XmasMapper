#include "ofApp.h"
#include "vector"

//--------------------------------------------------------------
void Potsu::setup(){
	
	world.init();
	world.setGravity(0, 1);
	world.createBounds(0, -100, ofGetWidth(), ofGetHeight() - 100);
	world.setFPS(30);
	world.registerGrabbing();
	
	snow.load("snow.png");
	snow.setAnchorPercent(0.5, 0.5);
}

//--------------------------------------------------------------
void Potsu::update(){
	if (currentSnowSqueres < (ofGetWidth() * ofGetHeight()) - 100) {
		if (ofRandom(0, 100) < 5) {
			float r = ofRandom(25, 40);
			ofVec2f v = generatePositionParameters();
			
			snows.push_back(ofPtr<Xmapper::XmapperSnow>(new Xmapper::XmapperSnow));
			snows.back().get() -> setPhysics(1.0, 0.5, 0.1);
			snows.back().get() -> setVelocity(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
			snows.back().get() -> setup(world.getWorld(), v, r);
			
			currentSnowSqueres += r * r * PI;
		}
	}
	else {
		snows.clear();
		currentSnowSqueres = 0;
	}
	world.update();
}

//--------------------------------------------------------------
void Potsu::draw(){
	ofSetColor(255);
	for (int i = 0; i < snows.size(); i++) {
//		snows[i].get() -> draw();
		ofPoint p = snows[i].get() -> getPosition();
		float size = snows[i].get() -> getRadius() * 5.0;
		snow.draw(p, size, size);
	}
	world.draw();
	drawTreeShadow();
	ofSetColor(255);
	ofRect(ofPoint(0, ofGetHeight() - 100), ofGetWidth(), 100);
}

//--------------------------------------------------------------
ofVec2f Potsu::generatePositionParameters() {
	float x;
	x = ofRandom(150, 650);
	ofVec2f v(x, -70);
	return v;
}

//--------------------------------------------------------------
void Potsu::drawTreeShadow() {
	ofFill();
	ofSetColor(0);
	float h_width = ofGetWidth() / 2.0;
	float height = ofGetHeight() - 100;
	
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2.0, 0);
	ofBeginShape();
		ofVertex(0, 0);
		ofVertex(-h_width, 0);
		ofVertex(-h_width, height);
		ofVertex(-(1.0 / 3.0) * h_width, 2.0 / 3.0 * height);
		ofVertex(-(2.0 / 3.0) * h_width, 2.0 / 3.0 * height);
		ofVertex(-(1.0 / 6.0) * h_width, 1.0 / 3.0 * height);
		ofVertex(-(1.0 / 3.0) * h_width, 1.0 / 3.0 * height);
	ofEndShape();
	
	ofBeginShape();
		ofVertex(0, 0);
		ofVertex(h_width, 0);
		ofVertex(h_width, height);
		ofVertex((1.0 / 3.0) * h_width, 2.0 / 3.0 * height);
		ofVertex((2.0 / 3.0) * h_width, 2.0 / 3.0 * height);
		ofVertex((1.0 / 6.0) * h_width, 1.0 / 3.0 * height);
		ofVertex((1.0 / 3.0) * h_width, 1.0 / 3.0 * height);
	ofEndShape();
	ofPopMatrix();
}