#include "processor.h"

class Gain : public Processor {
	float factor;
public:

	Gain (float factor);

	void processBuffer8(unsigned char* buffer8, int bufferSize) override;
	void processBuffer16(short* buffer16, int bufferSize) override;

	virtual ~Gain();
};