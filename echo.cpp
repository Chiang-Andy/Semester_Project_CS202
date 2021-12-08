#include "echo.h"

Echo::Echo(float f, float s, int h, int c) {
	factor = f;
	seconds = s;
	rate = h;
	channels = c;
}

void Echo::processBuffer8(unsigned char* buffer8, int bufferSize) {
	int d = seconds * rate * channels;
	for (int i = d; i < bufferSize; i++) {
		buffer8[i] = buffer8[i] * (1 - factor) + buffer8[i-d] * factor;
	}
}

void Echo::processBuffer16(short* buffer16, int bufferSize) {
	int d = seconds * rate * channels;
	for (int i = d; i < bufferSize; i++) {
		buffer16[i] = buffer16[i] * (1 - factor) + buffer16[i-d] * factor;
	}
}

Echo::~Echo() {

}