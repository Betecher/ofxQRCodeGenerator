#include "ofxQRCodeGenerator.h"

/**
 * Initialize parameters
 */
ofxQRCodeGenerator::ofxQRCodeGenerator() {}

ofxQRCodeGenerator::~ofxQRCodeGenerator() {}

//--------------------------------------------------------------
/**
 * receive url to generate qrcode
 * @params {string}  m padding from corner points area
 */
void ofxQRCodeGenerator::generate(string url) {
	const char *text = url.c_str();  // User-supplied text
	//const qrcodegen::QrCode::Ecc &errCorLvl = qrcodegen::QrCode::Ecc::LOW;  // Error correction level
	const qrcodegen::QrCode::Ecc &errCorLvl = qrcodegen::QrCode::Ecc::HIGH;  // Error correction level
	const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text, errCorLvl);

	for (int y = 0; y < qr.size; y++) {
		for (int x = 0; x < qr.size; x++) {
			qrCodeArr.push_back((qr.getModule(x, y) == 1 ? 1 : 0));
		}
	}
	qrSize = qr.size;
}

//--------------------------------------------------------------

void ofxQRCodeGenerator::draw(int size) {
	for (int i = 0; i < qrCodeArr.size(); i++) {
		if (qrCodeArr[i] == 1) ofSetColor(0);
		else ofSetColor(255);
		ofDrawRectangle((i%qrSize)*size, (i/qrSize)*size, size, size);
	}
}
