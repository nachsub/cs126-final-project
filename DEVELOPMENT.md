Could not access OpenFrameworksLib.log, fixed by running VS as admin.

used curl to update the database

Could not get the ball to bounce off the edges of the screen. It would keep going
in a direction and would not stop. Used vectors to handle game mechanics, and that 
seemed to fix it. 

Added ball.h and ball.cpp files, but got exception : 
Exception thrown at 0x0000000000000000 in cs126-final-project_debug.exe: 0xC0000005: Access violation executing location 0x0000000000000000.
To fix this, I moved ball_image.load(filename) from the constructor to the setup method in ball.cpp, 
which fixed it.

While adding ofxHttp and its dependecies through project generator, I had no errors, but needed 
to run as admin.

Get and Json request documentation was online, but I kept getting a 400 bad request error. To fix this, I had to 
add .json to the uri and it worked. Also had trouble parsing the Json, but using a foreach loop fixed this. 
