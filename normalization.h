#include "processor.h"

class Normal : public Processor {
public:

	/**
	 * @brief Construct a new Normal object
	 * 
	 */
	Normal ();

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
	 * @brief Destroy the Normal object
	 * 
	 */
	virtual ~Normal();
};