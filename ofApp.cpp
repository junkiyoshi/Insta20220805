#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableDepthTest();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}


//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int x = -220; x <= 220; x += 220) {

		for (int y = -220; y <= 220; y += 220) {

			int hue = ofRandom(255);
			ofColor color;

			auto rotate_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
			for (float z = 30; z < 100; z += 5) {

				ofPushMatrix();
				ofTranslate(x, y);

				ofRotateZ(ofMap(ofNoise(rotate_seed.z, z * 0.0025 + ofGetFrameNum() * 0.0035), 0, 1, -540, 540));
				ofRotateY(ofMap(ofNoise(rotate_seed.y, z * 0.0025 + ofGetFrameNum() * 0.0035), 0, 1, -540, 540));
				ofRotateX(ofMap(ofNoise(rotate_seed.x, z * 0.0025 + ofGetFrameNum() * 0.0035), 0, 1, -540, 540));

				ofFill();
				color.setHsb(hue, 255, 255);
				ofSetColor(color, ofMap(z, 100, 30, 200, 55));
				ofDrawRectangle(0, 0, z, 35, 35);

				color.setHsb((hue + 128) % 255, 255, 155);
				ofSetColor(color, ofMap(z, 100, 30, 200, 55));
				ofDrawRectangle(0, 0, -z, 35, 35);

				ofNoFill();
				color.setHsb(hue, 255, 255);
				ofSetColor(color);
				ofDrawRectangle(0, 0, z, 35, 35);

				color.setHsb((hue + 128) % 255, 255, 255);
				ofSetColor(color);
				ofDrawRectangle(0, 0, -z, 35, 35);


				ofPopMatrix();
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}