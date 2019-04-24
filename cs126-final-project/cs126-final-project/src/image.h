#pragma once

#ifndef _image_h
#define _image_h

#include "ofMain.h"
#include <string>

class Image {
 public: 
 const int image_width = 100;
 const int image_height = 70;

 Image(std::string shipname); 
 void setup();
 void update();
 void draw();

 ofImage image;
 std::string filename;

 int x;
 int y;
};

#endif // !_image_h
