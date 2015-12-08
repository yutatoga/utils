#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVec3f ellipsoidSurface(float half_width, float half_height, float half_depth, ofVec3f center = ofVec3f(0, 0, 0));
    ofVec3f ellipsoidInside(float half_width, float half_height, float half_depth, ofVec3f center = ofVec3f(0, 0, 0));
    
    int seedRandom;
    float timerTime;
};
