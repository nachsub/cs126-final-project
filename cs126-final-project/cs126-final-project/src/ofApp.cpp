#include "ofApp.h"


ofImage image;
ofImage ball;

const int image_width = 100;
const int image_height = 70;
const int ball_width = 50;
const int ball_height = 50;
int image_y;

bool moveLeft;
bool moveRight;
bool onRightEdge;
bool onLeftEdge;
bool onTopEdge;

int image_x; //spaceship's x value 
int ball_x;  //ball's x value
int ball_y;  //ball's y value

glm::vec2 ball_speed(3, 3);


//--------------------------------------------------------------
void ofApp::setup(){
	moveLeft = false;
	moveRight = false;
	image_x = ofGetWidth() / 2;
	ball_x = ofGetWidth() / 2;
	ball_y = ofGetHeight() / 2;
	image_y = ofGetHeight() - image_height;
	ball.load("basketball.png");
	image.load("spaceship.png");
	image.resize(image_width, image_height);
	ball.resize(ball_width, ball_height);
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofRectangle ballRect(ball_x, ball_y, ball_width, ball_height);
	ofRectangle rightImgRect(image_x + (image_width / 2), image_y, image_width / 2, image_height);
	ofRectangle leftImgRect(image_x, image_y, image_width / 2, image_height);
	
	if (!moveLeft && !moveRight && !(ballRect.intersects(rightImgRect) || ballRect.intersects(leftImgRect))) {
		ball_y = ball_y + 5;
		return;
	}
	//ball hits spaceship image
	if (ballRect.intersects(rightImgRect)) {
		moveRight = true;
		ball_speed.y = -ball_speed.y;
	} else if (ballRect.intersects(leftImgRect)) {
		moveLeft = true;
		ball_speed = (-1)*ball_speed;
	}
	//ball hits edge
	if (ball_x <= ball_width / 2) {
		ball_speed.x = -ball_speed.x;
	} else if (ball_y <= ball_width) {
		ball_speed.y = -ball_speed.y;
	} else if (ball_x >= ofGetWidth() - ball_width) {
		ball_speed.x = -ball_speed.x;
	}

	ball_x += ball_speed.x;
	ball_y += ball_speed.y;
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
