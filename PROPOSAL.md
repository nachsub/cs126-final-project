I will make breakout with a global leaderboard.
The user moves the paddle horizontally on the bottom of the screen, but 
the speed of the ball increases as you go. The score is calculated based on
how many times the ball hits the objects on the screen. 
It will display the top 5 players' usernames and their scores.

[OpenFrameworks Math Library](https://openframeworks.cc/documentation/math/)
[OpenFrameworks Glm Library](https://openframeworks.cc/documentation/glm/)
These will be used to handle the movement of the ball based on the object it hits.

[OpenFrameworks Gui Library](https://openframeworks.cc/documentation/ofxGui/)
This will be used to handle the graphics.

[FireBase](https://firebase.google.com/docs/cpp/setup#create_firebase_project)
This will be used to create and populate the database with user names and scores.

[ofxHttp](https://github.com/bakercp/ofxHTTP)
This will be used to make http requests to the database.

If I have finished the above, I plan on adding an online feature where 
someone running the game on their device can play against someone else. 
The user who scores the most points by the time the objects on the screen
are gone wins. 

[OpenFrameworks ofxOsc](https://openframeworks.cc/documentation/ofxOsc/)
[OpenFrameworks ofxNetwork](https://openframeworks.cc/documentation/ofxNetwork/)
These libraries handle the communication between devices.

