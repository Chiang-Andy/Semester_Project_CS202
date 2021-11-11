//example, needs revision -andy nov 10
#include "wav.h"
#include <fstream>
#include <string>


void Wav::readFile(const std::string &fileName){
	std::ifstream fileReader(filename, ios::binary | ios::in) 
	if(!fileReader.is_open()){
		std::cout << "fileIo unsuccessful" << std::endl;


	}else{
			fileReader.read((char*)&wavHeader, sizeof(wave_header));
			buffer = new unsigned char* buffer[waveHeader.data_bytes;]
			fileReader.read((char*)buffer, waveHeader.data_bytes);
			fileReader.close();
	}


}