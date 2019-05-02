#include "image.h"

Image::Image(std::string shipname) {
	filename = shipname;
}

void Image::setup() {
	x = ofGetWidth() / 2;
	y = ofGetHeight() - image_height;
	image.load(filename);
	image.resize(image_width, image_height);
}

void Image::draw() {
	image.draw(x, y);
}