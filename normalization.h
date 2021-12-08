#include "processor.h"

class Normal : public Processor {
public:

	Normal ();

	void processBuffer8(unsigned char* buffer8, int bufferSize) override;
	void processBuffer16(short* buffer16, int bufferSize) override;

	virtual ~Normal();
};