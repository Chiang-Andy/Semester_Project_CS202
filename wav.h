#include <iostream>
#include <string>
#include "wavHeader.h"
//#include "processor.h"

class Wav {
		std::string name;
    wav_header wavHeader;
    unsigned char* buffer8 = NULL;
		short* buffer16 = NULL;
public:
    /**
     * @brief Destroy the Wav object
     * 
     */
    virtual ~Wav();

    /**
     * @brief 
     * 
     * @param fileName 
     * @return true 
     * @return false 
     */
		bool readFile(const std::string &fileName);

    /**
     * @brief 
     * 
     */
		void printMetadata();

    /**
     * @brief 
     * 
     * @param outFileName 
     */
    void copyFile(const std::string &outFileName);

    /**
     * @brief 
     * 
     */
		void writeFile();

    /**
     * @brief Get the Buffer8 object
     * 
     * @return unsigned char* 
     */
    unsigned char *getBuffer8();

    /**
     * @brief Get the Buffer16 object
     * 
     * @return short* 
     */
    short *getBuffer16();

    /**
     * @brief Get the Buffer8 Size object
     * 
     * @return int 
     */
    int getBuffer8Size() const;

    /**
     * @brief Get the Buffer16 Size object
     * 
     * @return int 
     */
    int getBuffer16Size() const;

    /**
     * @brief 
     * 
     */
		void normal();

    /**
     * @brief 
     * 
     * @param factor 
     * @param seconds 
     */
		void echo(float factor, float seconds);

    /**
     * @brief 
     * 
     * @param factor 
     */
		void gain(float factor);
};