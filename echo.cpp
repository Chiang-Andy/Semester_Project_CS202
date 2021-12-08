#include "echo.h"

/**
 * @brief Construct a new Echo:: Echo object
 * 
 * @param f 
 * @param s 
 * @param h 
 * @param c 
 */
Echo::Echo(float f, float s, int h, int c) {
	factor = f;
	seconds = s;
	rate = h;
	channels = c;
}

/**
 * @brief 
 * 
 * @param buffer8 
 * @param bufferSize 
 */
void Echo::processBuffer8(unsigned char* buffer8, int bufferSize) {
	int d = seconds * rate * channels;
	for (int i = d; i < bufferSize; i++) {
		buffer8[i] = buffer8[i] * (1 - factor) + buffer8[i-d] * factor;
	}
}

/**
 * @brief 
 * 
 * @param buffer16 
 * @param bufferSize 
 */
void Echo::processBuffer16(short* buffer16, int bufferSize) {
	int d = seconds * rate * channels;
	for (int i = d; i < bufferSize; i++) {
		buffer16[i] = buffer16[i] * (1 - factor) + buffer16[i-d] * factor;
	}
}

/**
 * @brief Destroy the Echo:: Echo object
 * 
 */
Echo::~Echo() {

}