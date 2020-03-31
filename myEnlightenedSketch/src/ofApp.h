#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp{

public:

	void setup();

	void update();

	void draw();

	void mousePressed(int x, int y, int button);

	void mouseReleased(int x, int y, int button);

private:
	ofArduino arduino;

	void setupArduino(const int& version);

	void digitalPinChanged(const int& pinNum);

	void analogPinChanged(const int& pinNum);
		
};
