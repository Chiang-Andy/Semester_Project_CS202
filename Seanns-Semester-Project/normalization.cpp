#include <limits.h>
#include <stdlib.h>
#include "normalization.h"

Normal::Normal() {

}

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

Normal::~Normal() {

}