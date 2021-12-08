#pragma once

class Processor {
public:
	virtual void processBuffer8(unsigned char* buffer8, int bufferSize) = 0;
	virtual void processBuffer16(short* buffer16, int bufferSize) = 0;
};