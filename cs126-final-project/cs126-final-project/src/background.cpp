#include "background.h"
Background::Background(std::string background, int w, int h) {
	width = w;
	height = h;
	filename = background;
}

void Background::setup() {
	bg.load(filename);
}
