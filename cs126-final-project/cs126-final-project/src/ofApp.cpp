#include "ofApp.h"
using std::string;

//--------------------------------------------------------------
void ofApp::setup(){
	score = 0;
	ball.setup();
	image.setup();
	ofBackground(0, 0, 0);
	gui.setup();
	username = ofSystemTextBoxDialog("Input your username: ", username);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ball.ball_speed.x == 0) { return;  }
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
	if (ball.y >= ofGetHeight() - ball.ball_height && ball.ball_speed.x != 0) {
		ball.ball_speed.x = 0;
		ball.ball_speed.y = 0;
		std::string uri = "https://cs126-breakout.firebaseio.com/.json";

		const ofJson json = { {username, score} };

		// Create a client.
		ofxHTTP::Client client;

		// Create requests, used https://github.com/bakercp/ofxHttp
		ofxHTTP::JSONRequest json_request(uri);
		ofxHTTP::GetRequest get_request(uri);

		// Create a context.
		ofxHTTP::Context context;

		// Set custom session settings.
		// See the class documentation for many additional settings.
		ofxHTTP::ClientSessionSettings sessionSettings;

		// Use an iPhone X user agent string.
		sessionSettings.setUserAgent("Mozilla/5.0 (iPhone; CPU iPhone OS 11_0 like Mac OS X) AppleWebKit/604.1.38 (KHTML, like Gecko) Version/11.0 Mobile/15A372 Safari/604.1");

		// Set a 60 second keep-alive timeout (default is 8 seconds).
		sessionSettings.setKeepAliveTimeout(Poco::Timespan::SECONDS * 60);

		// Save the session settings with the context.
		context.setClientSessionSettings(sessionSettings);


		// Set the json request data.
		json_request.setJSON(json);


		// Do the query!
		try
		{
			// Execute the request within the given context.
			auto json_response = client.execute(json_request);
			auto get_response = client.execute(context, get_request);
			// Check the response.
			if (json_response->getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
			{
				// A successful response.
				ofLogNotice("ofApp::setup") << "Response success, expecting " << json_response->estimatedContentLength() << " bytes.";
				ofJson jn = get_response->json();
				std::vector<int> vec;      //vector of all scores
				std::map<int, string> map; //maps scores to usernames

				
			}
			else
			{
				ofLogError("ofApp::setup") << json_response->getStatus() << " " << json_response->getReason();
				ofLogError("ofApp::setup") << json_response->getStatus() << " " << get_response->getReason();
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
	gui.draw();
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
