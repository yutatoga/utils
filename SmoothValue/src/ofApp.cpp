#include "ofApp.h"

float getSmoothValue(float x){
    return x*x*(3.0-2.0*x);
}

float getSawValue(float timeSpeed){
    float time = ofGetElapsedTimef()*timeSpeed;
    return time - floor(time);
}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // saw wave style
    ofSetColor(ofColor::white);
    float sawValue = getSawValue(timeSpeed);
    ofDrawCircle(ofGetWidth()/(drawStyleNumber+1)*1, ofGetHeight()/2.0-ratio*sawValue, radius);
    
    // smooth saw value
    ofSetColor(ofColor::white);
    float smoothValue = getSmoothValue(sawValue);
    ofDrawCircle(ofGetWidth()/(drawStyleNumber+1)*2, ofGetHeight()/2.0-ratio*smoothValue, radius);
    
    // sine wave style
    ofSetColor(ofColor::white);
    float sinValue = sin(ofGetElapsedTimef()*timeSpeed);
    ofDrawCircle(ofGetWidth()/(drawStyleNumber+1)*3, ofGetHeight()/2.0-ratio*sinValue, radius);
    
    // cos wave style
    ofSetColor(ofColor::white);
    float cosValue = cos(ofGetElapsedTimef()*timeSpeed);
    ofDrawCircle(ofGetWidth()/(drawStyleNumber+1)*4, ofGetHeight()/2.0-ratio*cosValue, radius);
    
    // debug
    // - center line
    ofSetColor(ofColor::black);
    ofDrawLine(0, ofGetHeight()/2.0, ofGetWidth(), ofGetHeight()/2.0);
    // - ratio line
    ofSetColor(ofColor::gray);
    ofDrawLine(0, ofGetHeight()/2.0+ratio, ofGetWidth(), ofGetHeight()/2.0+ratio);
    ofDrawLine(0, ofGetHeight()/2.0-ratio, ofGetWidth(), ofGetHeight()/2.0-ratio);
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
