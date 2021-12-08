#include "limits.h"
#include "gainAdjustment.h"

/**
 * @brief Construct a new Gain:: Gain object
 * 
 * @param f 
 */
Gain::Gain(float f) {
	factor = f;
}

/**
 * @brief 
 * 
 * @param buffer8 
 * @param bufferSize 
 */
void Gain::processBuffer8(unsigned char* buffer8, int bufferSize) {
	for(int i = 0; i < bufferSize; i++) {
		buffer8[i] = 128 + (buffer8[i] - 128) * factor;
		if (buffer8[i] < 0) {
			buffer8[i] = 0;
		} else if (buffer8[i] > UCHAR_MAX) {
			buffer8[i] = 255;
		}
	}
}

/**
 * @brief 
 * 
 * @param buffer16 
 * @param bufferSize 
 */
void Gain::processBuffer16(short* buffer16, int bufferSize) {
	for(int i = 0; i < bufferSize; i++) {
		buffer16[i] *= factor;
		if (buffer16[i] < SHRT_MIN) {
			buffer16[i] = SHRT_MIN;
		} else if (buffer16[i] > SHRT_MAX) {
			buffer16[i] = SHRT_MAX;
		}
	}
}

/**
 * @brief Destroy the Gain:: Gain object
 * 
 */
Gain::~Gain() {

}