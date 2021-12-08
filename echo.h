#include "processor.h"

class Echo : public Processor {
	float factor;
	float seconds;
	int rate;
	int channels;
public:
	/**
	 * @brief Construct a new Echo object
	 * 
	 * @param factor 
	 * @param seconds 
	 * @param rate 
	 * @param channels 
	 */
	Echo(float factor, float seconds, int rate, int channels);
	
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
	 * @brief Destroy the Echo object
	 * 
	 */
	virtual ~Echo();
};