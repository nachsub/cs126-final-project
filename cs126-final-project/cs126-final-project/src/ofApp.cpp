#include "ofApp.h"


ofImage image;
ofImage game_over;

const int image_width = 100;
const int image_height = 70;

const int go_height = 700;
const int go_width = 700;

int image_x; //spaceship's x value 
int image_y;
int score;


string shipname = "spaceship.png";
string gameover = "gameover.png";
string ballname = "basketball.png";
const int ball_x_speed = 3; //ball x_speed
const int ball_y_speed = 3; //ball y_speed

Ball ball(ballname, ball_x_speed, ball_y_speed);

//--------------------------------------------------------------
void ofApp::setup(){
	score = 0;
	image_x = ofGetWidth() / 2;
	ball.setup();
	image_y = ofGetHeight() - image_height;
	image.load(shipname);
	game_over.load(gameover);
	image.resize(image_width, image_height);
	game_over.resize(ofGetWidth() / 2, ofGetHeight() / 2);
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofRectangle ballRect(ball.x, ball.y, ball.ball_width, ball.ball_height);
	ofRectangle rightImgRect(image_x + (image_width / 2), image_y, image_width / 2, image_height);
	ofRectangle leftImgRect(image_x, image_y, image_width / 2, image_height);
	//ball drops at beginning
	if (!ball.moveLeft && !ball.moveRight && !(ballRect.intersects(rightImgRect) || ballRect.intersects(leftImgRect))) {
		ball.y = ball.y + 5;
		return;
	}
	//ball hits spaceship image
	if (ballRect.intersects(rightImgRect)) {
		ball.moveRight = true;
		ball.ball_speed.y = -ball.ball_speed.y;
		score++;
	} else if (ballRect.intersects(leftImgRect)) {
		ball.moveLeft = true;
		ball.ball_speed = (-1)*ball.ball_speed;
		score++;
	}
	
	if (ball.x <= ball.ball_width / 2) {     //ball hits left edge
		ball.ball_speed.x = -ball.ball_speed.x;
	} else if (ball.y <= ball.ball_width) {  //ball hits top 
		ball.ball_speed.y = -ball.ball_speed.y;
	} else if (ball.x >= ofGetWidth() - ball.ball_width) { //ball hits right
		ball.ball_speed.x = -ball.ball_speed.x;
	}

	ball.x += ball.ball_speed.x;
	ball.y += ball.ball_speed.y;
}



//--------------------------------------------------------------
void ofApp::draw(){
	ball.draw();
	image.draw(image_x, ofGetHeight() - image_height);
	if (ball.y >= ofGetHeight() - ball.ball_height) {
		game_over.draw(0, 0);
	}
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
