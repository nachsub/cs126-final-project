#pragma once
#include "ball.h"
#include "ofxHTTP.h"
#include "ofxGui.h"
#include "image.h"
#include "background.h"
#include "ofMain.h"
#include <map>
#include <string>

class ofApp : public ofBaseApp{

	public:
		//game over screen width & height
		const int go_height = 700;
		const int go_width = 700;

		const int ball_x_speed = 3; //ball x_speed
		const int ball_y_speed = 3; //ball y_speed

		//number of scores on the leaderboard
		const static int leaderboard_count = 5;

		//file names for images
		std::string shipname = "spaceship.png";
		std::string gameover = "gameover.png";
		std::string ballname = "basketball.png";

		//json name
		std::string json_name;

		//username
		std::string username;
		
		//list of scores
		ofParameter<int> scores[leaderboard_count];
		ofxPanel gui;

		int score;

		Ball ball = Ball(ballname, ball_x_speed, ball_y_speed);
		Image image = Image(shipname);

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


};
