#pragma once

#ifndef _background_h
#define _background_h

#include "ofMain.h"
#include <string>

class Background {
public:
	int width;
	int height;

	Background(std::string background, int w, int h);
	void setup();
	void update();
	void draw();

	ofImage bg;
	std::string filename;
};

#endif // !_image_h
