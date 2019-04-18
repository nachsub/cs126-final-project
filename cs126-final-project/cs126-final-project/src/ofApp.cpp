#include "ofApp.h"


ofImage image;
ofImage ball;

const int image_width = 80;
const int image_height = 80;
const int ball_width = 40;
const int ball_height = 40;

bool isMoving;
bool moveLeft;
bool moveRight;

int image_x; //spaceship's x value 
int ball_x;  //ball's x value
int ball_y;  //ball's y value


//--------------------------------------------------------------
void ofApp::setup(){
	isMoving = false;
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
	ofRectangle imgRect(image_x, ofGetHeight() - image_height, image_width, image_height);
	ofRectangle rightBallRect(ball_x + ball_width / 2, ball_y, ball_width / 2, ball_height);
	ofRectangle leftBallRect(ball_x, ball_y, ball_width / 2, ball_height);

	if (!isMoving) {
		ball_y = ball_y + 5;
	}
	if (imgRect.inside(rightBallRect)) {
		moveRight = true;
	}
	if (imgRect.inside(leftBallRect)) {
		moveLeft = true;
	}
	if (moveLeft && ball_x >= 0 && ball_x < ofGetWidth() - ball_width) {
		ball_x = ball_x - 10;
		ball_y = ball_y - 10;
	}
	if (moveRight && ball_x < ofGetWidth() - ball_width) {
		ball_x = ball_x + 10;
		ball_y = ball_y - 10;
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
