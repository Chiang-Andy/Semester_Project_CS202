#include "processor.h"

class Gain : public Processor {
	float factor;
public:

	/**
	 * @brief Construct a new Gain object
	 * 
	 * @param factor 
	 */
	Gain (float factor);

	/**
	 * @brief 
	 * 
	 * @param buffer8 
	 * @param bufferSize 
	 */
	void processBuffer8(unsigned char* buffer8, int bufferSize) override;
	
	/**
	 * @brief 
	 * 
	 * @param buffer16 
	 * @param bufferSize 
	 */
	void processBuffer16(short* buffer16, int bufferSize) override;

	/**
	 * @brief Destroy the Gain object
	 * 
	 */
	virtual ~Gain();
};