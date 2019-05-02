#include "ball.h"

Ball::Ball(string filename, const int x_speed, const int y_speed) {
	this->filename = filename;
	ball_speed = glm::vec2(x_speed, y_speed);
}
void Ball::setup() {
	ball_image.load(filename);
	ball_image.resize(ball_width, ball_height);
    moveLeft = false;
	moveRight = false;
	x = ofGetWidth() / 2;
	y = ofGetHeight() / 2;
}

void Ball::draw() {
	ball_image.draw(x, y);
}