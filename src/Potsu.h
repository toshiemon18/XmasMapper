#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

namespace Xmapper {
	class XmapperSnow : public ofxBox2dCircle {
		public:
			ofColor snowColor = (255, 255, 255);
			void draw() {
				float radius = getRadius();
				glPushMatrix();
				glTranslatef(getPosition().x, getPosition().y, 0);
				ofFill();
				ofSetColor(snowColor, 100);
				ofCircle(0, 0, radius);
				ofSetColor(snowColor, 150);
				ofCircle(0, 0, radius * 0.8);
				glPopMatrix();
			};
	};
};

class Potsu : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofVec2f generatePositionParameters();
		void drawTreeShadow();
	
		ofxBox2d world;
		ofImage snow;
		vector <ofPtr<Xmapper::XmapperSnow>> snows;
		float currentSnowSqueres = 0.0;
};
