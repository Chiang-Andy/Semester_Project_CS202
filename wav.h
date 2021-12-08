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
    virtual ~Wav();
		bool readFile(const std::string &fileName);
		void printMetadata();
    void copyFile(const std::string &outFileName);
		void writeFile();
    unsigned char *getBuffer8();
    short *getBuffer16();
    int getBuffer8Size() const;
    int getBuffer16Size() const;
		void normal();
		void echo(float factor, float seconds);
		void gain(float factor);
};