#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    void drawAverageRandomCircle(ofVec2f center = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0), float referenceCircleRadius = 100, int randomPointNumber = 100, bool enableSeedRandom = false);
    void drawRandomCircle(ofVec2f center = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0), float referenceCircleRadius = 100, int randomPointNumber = 100, bool enableSeedRandom = false);
    void drawRandomSphereSurface(float referenceSphereRadius, int randomPointNumber, bool enableSeedRandom = false);
    void drawRandomSphere(float referenceSphereRadius, int randomPointNumber, bool enableSeedRandom = false);
    
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

    int seedRandom;
    int timerTime;
};
