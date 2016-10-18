#pragma once

#include "ofMain.h"
#include "QrCode.hpp"

class ofxQRCodeGenerator {
public:
	ofxQRCodeGenerator();
	~ofxQRCodeGenerator();

	int qrSize;
	vector<int> qrCodeArr;

	void generate(string url);
	void draw(int size);
};
