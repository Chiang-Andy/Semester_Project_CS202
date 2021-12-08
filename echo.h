#include "processor.h"

class Echo : public Processor {
	float factor;
	float seconds;
	int rate;
	int channels;
public:
	Echo(float factor, float seconds, int rate, int channels);
	
	void processBuffer8(unsigned char* buffer8, int bufferSize) override;
	void processBuffer16(short* buffer16, int bufferSize) override;

	virtual ~Echo();
};