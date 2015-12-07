#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    seedRandom = 1;
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
    float horizontalRadius = 100;
    float verticalRadius = 60;
    
    int rowSize = 2.0;
    int columnSize = 4.0;
    
    int row; // start from zero
    int column; // start from zero
    
    // ofSeedRandom()
    // ellipse ourline
    row = 0;
    column = 0;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofDrawBitmapStringHighlight("randomEllipseOutline", -80, verticalRadius+40);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawCircle(randomEllipseOutline(horizontalRadius, verticalRadius), 1);
    }
    ofPopMatrix();
    
    // inside ellipse
    row = 0;
    column = 1;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofDrawBitmapStringHighlight("randomEllipseInside", -70, verticalRadius+40);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawCircle(randomEllipseInside(horizontalRadius, verticalRadius), 1);
    }
    ofPopMatrix();
    
    // spheroid surface
    row = 0;
    column = 2;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofDrawBitmapStringHighlight("randomSpheroidSurface", -85, verticalRadius+40);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(randomSpheroidSurface(horizontalRadius, verticalRadius), 1);
    }
    ofPopMatrix();
    
    // inside spheroid
    row = 0;
    column = 3;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofDrawBitmapStringHighlight("randomSpheroidInside", -80, verticalRadius+40);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(randomSpheroidInside(horizontalRadius, verticalRadius), 1);
    }
    ofPopMatrix();
    
    // ofSeedRandom(seedRandom)
    // ellipse surface
    row = 1;
    column = 0;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofSeedRandom(seedRandom);
    ofDrawBitmapStringHighlight("randomEllipseOutline", -80, verticalRadius+40);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawCircle(randomEllipseOutline(horizontalRadius, verticalRadius), 1);
    }
    ofSeedRandom();
    ofPopMatrix();
    
    // inside ellipse
    row = 1;
    column = 1;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofSeedRandom(seedRandom);
    ofDrawBitmapStringHighlight("randomEllipseInside", -70, verticalRadius+40);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawCircle(randomEllipseInside(horizontalRadius, verticalRadius), 1);
    }
    ofSeedRandom();
    ofPopMatrix();
    
    // spheroid surface
    row = 1;
    column = 2;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofDrawBitmapStringHighlight("randomSpheroidSurface", -85, verticalRadius+40);
    ofRotateY(ofGetFrameNum());
    ofSeedRandom(seedRandom);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(randomSpheroidSurface(horizontalRadius, verticalRadius), 1);
    }
    ofSeedRandom();
    ofPopMatrix();
    
    // inside spheroid
    row = 1;
    column = 3;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/columnSize*column + ofGetWidth()/columnSize/2.0, ofGetHeight()/rowSize*row + ofGetHeight()/rowSize/2.0);
    ofDrawBitmapStringHighlight("randomSpheroidInside", -80, verticalRadius+40);
    ofRotateY(ofGetFrameNum());
    ofSeedRandom(seedRandom);
    for (int i = 0; i < pointNumber; i++) {
        ofDrawSphere(randomSpheroidInside(horizontalRadius, verticalRadius), 1);
    }
    ofSeedRandom();
    ofPopMatrix();
}

ofVec2f ofApp::randomEllipseOutline(float horizontalRadius, float verticalRadius){
    float theta = ofRandom(0, TWO_PI);
    float x = horizontalRadius * cos(theta);
    float y = verticalRadius * sin(theta);
    ofVec2f position(x, y);
    return position;
}

ofVec2f ofApp::randomEllipseInside(float horizontalRadius, float verticalRadius, ofVec2f center){
    float theta = ofRandom(0, TWO_PI);
    float randomRadiusRate = sqrt(ofRandom(0, 1));
    float x = randomRadiusRate * horizontalRadius * cos(theta);
    float y = randomRadiusRate * verticalRadius * sin(theta);
    ofVec2f position(x, y);
    position += center;
    return position;
}

ofVec3f ofApp::randomSpheroidSurface(float horizontalRadius, float verticalRadius, ofVec3f center){
    float theta = acos(1-2*ofRandom(0, 1));
    float r = verticalRadius * sin(theta);
    float n = ofRandom(0, 1) * TWO_PI;
    float x = horizontalRadius * cos(theta);
    float y = r * sin(n);
    float z = r * cos(n);
    ofVec3f position(x, y, z);
    position += center;
    return position;
}

ofVec3f ofApp::randomSpheroidInside(float horizontalRadius, float verticalRadius, ofVec3f center){
    float theta = acos(1-2*ofRandom(0, 1));
    float randomRadiusRate = sqrt(ofRandom(0, 1));
    float r = randomRadiusRate * verticalRadius * sin(theta);
    float n = ofRandom(0, 1) * TWO_PI;
    float x = randomRadiusRate * horizontalRadius * cos(theta);
    float y = r * sin(n);
    float z = r * cos(n);
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
