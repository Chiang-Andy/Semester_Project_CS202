#pragma once

class Processor {
public:
	/**
	 * @brief 
	 * 
	 * @param buffer8 
	 * @param bufferSize 
	 */
	virtual void processBuffer8(unsigned char* buffer8, int bufferSize) = 0;
	
	/**
	 * @brief 
	 * 
	 * @param buffer16 
	 * @param bufferSize 
	 */
	virtual void processBuffer16(short* buffer16, int bufferSize) = 0;
};