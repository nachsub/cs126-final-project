#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	score = 0;
	ball.setup();
	image.setup();
	game_over.load(gameover);
	game_over.resize(ofGetWidth() / 2, ofGetHeight() / 2);
	ofBackground(0, 0, 0);

	std::string uri = "https://cs126-breakout.firebaseio.com/";

	std::multimap<std::string, std::string> formFields =
	{
		{ "test_0", "123" },
		{ "test_1", "321" }
	};

	

	ofxHTTP::Client client;
	ofxHTTP::PostRequest request(uri);
	request.addFormFields(formFields);

	try
	{
		// Execute the request.
		auto response = client.execute(request);

		std::cout << "nig";

		std::cout << response->getStatus();
		// Check the response.
		if (response->getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
		{
			// A successful response.
			ofLogNotice("ofApp::setup") << "Response success, expecting " << response->estimatedContentLength() << " bytes.";

		}
		else
		{
			ofLogError("ofApp::setup") << response->getStatus() << " " << response->getReason();
		}
	}
	catch (const Poco::Exception& exc)
	{
		ofLogError("ofApp::setup") << exc.displayText();
	}
	catch (const std::exception& exc)
	{
		ofLogError("ofApp::setup") << exc.what();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	ofRectangle ballRect(ball.x, ball.y, ball.ball_width, ball.ball_height);
	ofRectangle rightImgRect(image.x + (image.image_width / 2), image.y, image.image_width / 2, image.image_height);
	ofRectangle leftImgRect(image.x, image.y, image.image_width / 2, image.image_height);
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
	image.draw();
	if (ball.y >= ofGetHeight() - ball.ball_height) {
		game_over.draw(0, 0);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'd' && image.x < ofGetWidth() - image.image_width){
		image.x += 20;
	} 
	if (key == 'a' && image.x >= 0) {
		image.x -= 20;
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
