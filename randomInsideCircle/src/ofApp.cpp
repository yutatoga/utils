#include "ofApp.h"

// ispired by http://marupeke296.com/TIPS_No18_Randoms.html

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(128);
    ofSetSphereResolution(4);
    ofEnableDepthTest();
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
    // draw as ofSeedRandom()
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*1-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0-ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawRandomCircle", -60, ofGetWidth()/4.0/2.0);
    drawRandomCircle(ofVec2f(0, 0), ofGetWidth()/4.0/2.0*0.8, 100);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*2-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0-ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawAverageRandomCircle", -90, ofGetWidth()/4.0/2.0);
    drawAverageRandomCircle(ofVec2f(0, 0), ofGetWidth()/4.0/2.0*0.8, 100);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*3-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0-ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawRandomSphere", -60, ofGetWidth()/4.0/2.0);
    ofRotateY(ofGetFrameNum());
    drawRandomSphere(ofGetWidth()/4.0/2.0*0.8, 1000);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*4-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0-ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawRandomSphereSurface", -80, ofGetWidth()/4.0/2.0);
    ofRotateY(ofGetFrameNum());
    drawRandomSphereSurface(ofGetWidth()/4.0/2.0*0.8, 1000);
    ofPopMatrix();
    
    // draw as ofSeedRandom(seedRandom)
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*1-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0+ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawRandomCircle", -60, ofGetWidth()/4.0/2.0);
    ofSeedRandom(seedRandom);
    drawRandomCircle(ofVec2f(0, 0), ofGetWidth()/4.0/2.0*0.8, 100);
    ofSeedRandom();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*2-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0+ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawAverageRandomCircle", -90, ofGetWidth()/4.0/2.0);
    ofSeedRandom(seedRandom);
    drawAverageRandomCircle(ofVec2f(0, 0), ofGetWidth()/4.0/2.0*0.8, 100);
    ofSeedRandom();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*3-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0+ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawRandomSphere", -60, ofGetWidth()/4.0/2.0);
    ofRotateY(ofGetFrameNum());
    ofSeedRandom(seedRandom);
    drawRandomSphere(ofGetWidth()/4.0/2.0*0.8, 1000);
    ofSeedRandom();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0*4-ofGetWidth()/4.0/2.0, ofGetHeight()/2.0+ofGetHeight()/2.0/2.0);
    ofDrawBitmapStringHighlight("drawRandomSphereSurface", -80, ofGetWidth()/4.0/2.0);
    ofRotateY(ofGetFrameNum());
    ofSeedRandom(seedRandom);
    drawRandomSphereSurface(ofGetWidth()/4.0/2.0*0.8, 1000);
    ofSeedRandom();
    ofPopMatrix();
}

ofVec2f ofApp::averageRandomCircle(ofVec2f center, float radius){
    // average random position inside a circle
    float theta = ofRandom(0, TWO_PI);
    float randomRadius = sqrt(ofRandom(0, 1))*radius;
    ofVec2f position(center.x+randomRadius*cos(theta), center.y+randomRadius*sin(theta));
    return position;
}

void ofApp::drawAverageRandomCircle(ofVec2f center, float referenceCircleRadius, int randomPointNumber, bool enableSeedRandom){
    // reference circle
    ofNoFill();
    ofDrawCircle(center.x, center.y, referenceCircleRadius);
    
    // random inside the reference circle
    if (enableSeedRandom) {
        ofSeedRandom(1);
    }
    ofFill();
    for (int i = 0; i < randomPointNumber; i++) {
        ofDrawCircle(averageRandomCircle(center, referenceCircleRadius), 1);
    }
    ofSeedRandom();
}

ofVec2f ofApp::randomCircle(ofVec2f center, float radius){
    // random position inside a circle
    float theta = ofRandom(0, TWO_PI);
    float randomRadius = ofRandom(0, radius);
    ofVec2f position(center.x+randomRadius*cos(theta), center.y+randomRadius*sin(theta));
    return position;
}

void ofApp::drawRandomCircle(ofVec2f center, float referenceCircleRadius, int randomPointNumber, bool enableSeedRandom){
    // reference circle
    ofNoFill();
    ofDrawCircle(center.x, center.y, referenceCircleRadius);
    
    // random inside the reference circle
    if (enableSeedRandom){
        ofSeedRandom(1);
    }
    ofFill();
    for (int i = 0; i < randomPointNumber; i++) {
        ofDrawCircle(randomCircle(center, referenceCircleRadius), 1);
    }
    ofSeedRandom();
}

ofVec3f ofApp::randomSphereSurface(float radius, ofVec3f center){
    float theta = acos(1-2*ofRandom(0, 1));
    float r = radius*sin(theta);
    float n = ofRandom(0, 1)*TWO_PI;
    float x = radius*cos(theta);
    float y = r*sin(n);
    float z = r*cos(n);
    ofVec3f position(x, y, z);
    position += center;
    return position;
}

void ofApp::drawRandomSphereSurface(float referenceSphereRadius, int randomPointNumber, bool enableSeedRandom){
    if (enableSeedRandom) {
        ofSeedRandom(1);
    }
    for (int i = 0; i < randomPointNumber; i++) {
        ofDrawSphere(randomSphereSurface(referenceSphereRadius), 1);
    }
    ofSeedRandom();
}

ofVec3f ofApp::randomSphere(float radius, ofVec3f center){
    float theta = acos(1-2*ofRandom(0, 1));
    float r0 = sqrt(ofRandom(0, 1)) * radius;
    float r = r0*sin(theta);
    float n = ofRandom(0, 1)*TWO_PI;
    float x = r0*cos(theta);
    float y = r*sin(n);
    float z = r*cos(n);
    ofVec3f position(x, y, z);
    position += center;
    return position;
}

void ofApp::drawRandomSphere(float referenceSphereRadius, int randomPointNumber, bool enableSeedRandom){
    if (enableSeedRandom) {
        ofSeedRandom(1);
    }
    for (int i = 0; i < randomPointNumber; i++) {
        ofDrawSphere(randomSphere(referenceSphereRadius), 1);
    }
    ofSeedRandom();
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
