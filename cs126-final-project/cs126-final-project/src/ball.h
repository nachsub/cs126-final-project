#pragma once

#ifndef _ball_h
#define _ball_h

#include "ofMain.h"
#include <string>

class Ball {
  public: 
   ofImage ball_image;
   const int ball_width = 50;
   const int ball_height = 50;

   Ball(string filename, const int x_speed, const int y_speed); //constructor takes in the ball image filename   
   void setup();
   void update();
   void draw(); 

   std::string filename;
   glm::vec2 ball_speed;
   bool moveLeft;
   bool moveRight;
   int x;
   int y;
};
#endif // _ball_h


