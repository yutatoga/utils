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
		
    ofVec2f randomEllipseOutline(float horizontalRadius, float verticalRadius);
    ofVec2f randomEllipseInside(float horizontalRadius, float verticalRadius, ofVec2f center = ofVec2f(0, 0));
    ofVec3f randomSpheroidSurface(float horizontalRadius, float verticalRadius, ofVec3f center = ofVec3f(0, 0, 0));
    ofVec3f randomSpheroidInside(float horizontalRadius, float verticalRadius, ofVec3f center = ofVec3f(0, 0, 0));
    
    int seedRandom;
    int timerTime;
};
