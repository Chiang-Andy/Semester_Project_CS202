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
     * @brief Reads a file into the class
     * 
     * @param fileName Determines the wav file to be used by the program
     * @return true True if the file was read successfully
     * @return false False if the file was unable to be read or was formatted incorrectly
     */
		bool readFile(const std::string &fileName);

    /**
     * @brief Prints the file's file name, sample rate, bits per sample, and audio type
     * 
     */
		void printMetadata();

    /**
     * @brief Duplicates the audio file
     * 
     * @param outFileName Determines the name of the copied file
     */
    void copyFile(const std::string &outFileName);

    /**
     * @brief Updates the given file
     * 
     */
		void writeFile();

    /**
     * @brief Returns the array of 8-bit samples
     * 
     * @return unsigned char* 
     */
    unsigned char *getBuffer8();

    /**
     * @brief Returns the array of 16-bit samples
     * 
     * @return short* 
     */
    short *getBuffer16();

    /**
     * @brief Get the number of samples in the file
     * 
     * @return int 
     */
    int getBuffer8Size() const;

    /**
     * @brief Get the number of samples in the file
     * 
     * @return int 
     */
    int getBuffer16Size() const;

    /**
     * @brief Applies normalization processor
     * 
     */
		void normal();

    /**
     * @brief Applies echo processor
     * 
     * @param factor Determines the echo's amplitude
     * @param seconds Determines in seconds the time between echoes
     */
		void echo(float factor, float seconds);

    /**
     * @brief Applies gain adjustment processor
     * 
     * @param factor Determines the amount that the gain is multiplied by
     */
		void gain(float factor);
};
