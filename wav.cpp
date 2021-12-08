#include <fstream>
#include "wav.h"
#include "normalization.h"
#include "echo.h"
#include "gainAdjustment.h"

Wav::~Wav() {
	
}

// 1-8 bits: unsigned int
// 9+ bits: signed int

bool Wav::readFile (const std::string &filename){

	std::ifstream file(filename, std::ios::binary | std::ios::in);

	if(file.is_open()){
		name = filename;
		file.read((char*)& wavHeader, sizeof(wavHeader));
		if(wavHeader.bit_depth <= 8) {
			buffer8 = new unsigned char[wavHeader.data_bytes];
			file.read((char*)buffer8,wavHeader.data_bytes);
			/*for (int i = 0; i < 256; i++) {
				std::cout << (int)buffer8[i] << " ";
			}*/
		}
		if(std::string {wavHeader.riff_header, 4} != "RIFF"){
			return false;
		}
		if(std::string {wavHeader.wav_header, 4} != "WAVE"){
			return false;
		} else {
			buffer16 = new short[wavHeader.data_bytes];
			file.read((char*)buffer16,wavHeader.data_bytes);
			/*for (int i = 0; i < 256; i++) {
				std::cout << buffer16[i] << " ";
			}*/
		}
		file.close();
		return true;
	} else {
		return false;
	}
}

void Wav::printMetadata() {
	std::cout << "Filename: " << name << std::endl;
	std::cout << "Sample rate: " << wavHeader.sample_rate << std::endl;
	std::cout << "Bits per sample: " << wavHeader.bit_depth << std::endl;
	switch (wavHeader.num_channels) {
		case 1:
			std::cout << "Mono" << std::endl;
			break;
		case 2:
			std::cout << "Stereo" << std::endl;
			break;
		default:
			std::cout << "Number of channels: " << wavHeader.num_channels << std::endl;
	}
//	std::cout << "data bytes: " << wavHeader.data_bytes << std::endl;
	
}

void Wav::copyFile(const std::string &outFileName) {
	std::ifstream inf(name, std::ios::binary | std::ios::out);
	std::ofstream outf(outFileName, std::ios::binary | std::ios::out);
	outf << inf.rdbuf();
}

void Wav::writeFile() {
	std::ofstream file(name, std::ios::binary | std::ios::out);
	if(file.is_open())
		{
			file.write((char*)&wavHeader, sizeof(wav_header));
			if (wavHeader.bit_depth==8) {
				for(int i = 0; i < wavHeader.data_bytes; i++) {
					file << buffer8[i];
				}
			}
			else {
        std::cout << getBuffer16Size() << std::endl;
				for(int i = 0; i < wavHeader.data_bytes; i++) {
					file << buffer16[i];
				}
			}
			file.close();
		}
}

unsigned char* Wav::getBuffer8() {
	return buffer8;
}

short* Wav::getBuffer16() {
	return buffer16;
}

int Wav::getBuffer8Size() const {
	return wavHeader.data_bytes;
}

int Wav::getBuffer16Size() const {
	return wavHeader.data_bytes;
}

void Wav::normal() {
	Processor * p = new Normal();
	if (wavHeader.num_channels == 1) {
		p->processBuffer8(getBuffer8(), getBuffer8Size());
	} else {
		p->processBuffer16(getBuffer16(), getBuffer16Size());
	}
}
void Wav::echo(float factor, float seconds) {
	Processor * p = new Echo(factor, seconds, wavHeader.sample_rate, wavHeader.num_channels);
	if (wavHeader.num_channels == 1) {
		p->processBuffer8(getBuffer8(), getBuffer8Size());
	} else {
		p->processBuffer16(getBuffer16(), getBuffer16Size());
	}
}
void Wav::gain(float factor) {
	Processor * p = new Gain(factor);
	if (wavHeader.num_channels == 1) {
		p->processBuffer8(getBuffer8(), getBuffer8Size());
	} else {
		p->processBuffer16(getBuffer16(), getBuffer16Size());
	}
}
