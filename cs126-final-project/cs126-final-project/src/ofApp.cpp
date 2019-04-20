#include "ofApp.h"


ofImage image;
ofImage ball;

const int image_width = 80;
const int image_height = 80;
const int ball_width = 40;
const int ball_height = 40;

bool moveLeft;
bool moveRight;

int image_x; //spaceship's x value 
int ball_x;  //ball's x value
int ball_y;  //ball's y value


//--------------------------------------------------------------
void ofApp::setup(){
	moveLeft = false;
	moveRight = false;
	image_x = ofGetWidth() / 2;
	ball_x = ofGetWidth() / 2;
	ball_y = ofGetHeight() / 2;
	ball.load("basketball.png");
	image.load("spaceship.png");
	image.resize(image_width, image_height);
	ball.resize(ball_width, ball_height);
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	glm::vec2 vec(1, 1);
	ofRectangle ballRect(ball_x, ball_y, ball_width, ball_height);
	ofRectangle rightImgRect(image_x + (image_width / 2), ofGetHeight() - image_height, image_width / 2, image_height);
	ofRectangle leftImgRect(image_x, ofGetHeight() - image_height, image_width / 2, image_height);
	ballRect.standardize();
	rightImgRect.standardize();
	leftImgRect.standardize();
	if (!moveLeft && !moveRight) {
		ball_y = ball_y + 5;
	}

	if (ballRect.intersects(rightImgRect)) {
		moveRight = true;
	} else if (ballRect.intersects(leftImgRect)) {
		moveLeft = true;
	}

	if (ball_y >= ofGetHeight() - ball_height && moveLeft) {
		ball_x = ball_x - 1;
		ball_y = ball_y + 2;
	}
	if (ball_y >= ofGetHeight() - ball_height && moveRight) {
		ball_x = ball_x + 1;
		ball_y = ball_y + 2;
	}
	if (ball_x <= ball_width && moveLeft) {
		ball_x = ball_x + 2;
		ball_y = ball_y - 2;
	}
	if (ball_x <= ball_width && moveRight) {
		ball_x = ball_x + 2;
		ball_y = ball_y + 2;
	}
	if (ball_x >= ofGetWidth() - ball_width && moveLeft) {
		ball_x = ball_x - 2;
		ball_y = ball_y - 2;
	}
	if (ball_x >= ofGetWidth() - ball_width && moveRight) {
		ball_x = ball_x - 2;
		ball_y = ball_y + 2;
	}

	if (moveLeft && ball_x >= 0 && ball_x < ofGetWidth() - ball_width) {
		ball_x = ball_x - 1;
		ball_y = ball_y - 2;
	}
	if (moveRight && ball_x <= ofGetWidth() - ball_width) {
		ball_x = ball_x + 2;
		ball_y = ball_y - 3;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ball.draw(ball_x, ball_y);
	image.draw(image_x, ofGetHeight() - image_height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'd' && image_x < ofGetWidth() - image_width){
		image_x += 20;
	} 
	if (key == 'a' && image_x >= 0) {
		image_x -= 20;
	}
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
