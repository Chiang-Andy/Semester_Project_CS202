#include <limits.h>
#include <stdlib.h>
#include "normalization.h"

/**
 * @brief Construct a new Normal:: Normal object
 * 
 */
Normal::Normal() {

}

/**
 * @brief 
 * 
 * @param buffer8 
 * @param bufferSize 
 */
void Normal::processBuffer8(unsigned char* buffer8, int bufferSize) {
	float factor;
	char max = 1;
	for (int i = 0; i < bufferSize; i++) {
		if (abs(buffer8[i] - 128) > max) {
			max = buffer8[i] - 128;
		}
	}
	factor = UCHAR_MAX / max;
	for(int i = 0; i < bufferSize; i++) {
		buffer8[i] *= factor;
	}
}

/**
 * @brief 
 * 
 * @param buffer16 
 * @param bufferSize 
 */
void Normal::processBuffer16(short* buffer16, int bufferSize) {
	float factor;
	short max = 1;
	for (int i = 0; i < bufferSize; i++) {
		if (abs(buffer16[i]) > max) {
			max = buffer16[i];
		}
	}
	factor = SHRT_MAX / max;
	for(int i = 0; i < bufferSize; i++) {
		buffer16[i] *= factor;
	}
}

/**
 * @brief Destroy the Normal:: Normal object
 * 
 */
Normal::~Normal() {

}