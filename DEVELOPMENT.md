Could not access OpenFrameworksLib.log, fixed by running vs as admin.

used curl to update the database

Could not get the ball to bounce off the edges of the screen. It would keep going
in a direction and would not stop. Used vectors to handle game mechanics, and that 
seemed to fix it. 

Added ball.h and ball.cpp files, but got exception : 
Exception thrown at 0x0000000000000000 in cs126-final-project_debug.exe: 0xC0000005: Access violation executing location 0x0000000000000000.
To fix this, I moved ball_image.load(filename) from the constructor to the setup method in ball.cpp, 
which fixed it.