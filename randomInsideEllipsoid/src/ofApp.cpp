#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    seedRandom = 0;
    timerTime = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    if ((int)ofGetElapsedTimef() % 3 == 0 && (ofGetElapsedTimef() - timerTime) > 1) {
        seedRandom = (int)ofRandom(-100, 100);
        timerTime = ofGetElapsedTimef();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int pointNumber = 500;
    float half_width = 100;
    float half_height = 30;
    float half_depth = 100;
    
    int rowSize = 2.0;
    int columnSize = 2.0;
    int row; // start from zero
    int column; // start from zero
    
    // ofSeedRandom();
    row = 0;
    column = 0;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofRotateY(ofGetFrameNum());
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(ellipsoidSurface(half_width, half_height, half_depth), 1);
    }
    ofPopMatrix();
    
    row = 0;
    column = 1;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofRotateY(ofGetFrameNum());
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(ellipsoidInside(half_width, half_height, half_depth), 1);
    }
    ofPopMatrix();
    
    // ofSeedRandom(seedRandom)
    row = 1;
    column = 0;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofRotateY(ofGetFrameNum());
    ofSeedRandom(seedRandom);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(ellipsoidSurface(half_width, half_height, half_depth), 1);
    }
    
    ofSeedRandom();
    ofPopMatrix();

    row = 1;
    column = 1;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofRotateY(ofGetFrameNum());
    ofSeedRandom(seedRandom);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(ellipsoidInside(half_width, half_height, half_depth), 1);
    }
    ofSeedRandom();
    ofPopMatrix();
}

ofVec3f ofApp::ellipsoidSurface(float half_width, float half_height, float half_depth, ofVec3f center){
    float u = ofRandom(0, TWO_PI);
    float v = acos(1-2*ofRandom(0, 1));
    float x = half_width*cos(u)*sin(v);
    float y = half_height*sin(u)*sin(v);
    float z = half_depth*cos(v);
    ofVec3f position(x, y, z);
    position += center;
    return position;
}

ofVec3f ofApp::ellipsoidInside(float half_width, float half_height, float half_depth, ofVec3f center){
    float u = ofRandom(0, TWO_PI);
    float v = acos(1-2*ofRandom(0, 1));
    float radiusRate = sqrt(ofRandom(0, 1));
    float x = radiusRate*half_width*cos(u)*sin(v);
    float y = radiusRate*half_height*sin(u)*sin(v);
    float z = radiusRate*half_depth*cos(v);
    ofVec3f position(x, y, z);
    position += center;
    return position;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
