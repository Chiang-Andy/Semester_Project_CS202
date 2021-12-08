#include <iostream>
#include <fstream>
#include <string>
#include "wav.h"

/**
 * @brief Start menu UI
 * 
 * @return int 
 */
int startMenu() {
	int s;
	std::cout << "Input 1 to edit wav file or 0 to exit program" << std::endl;
	std::cin >> s;
	return s;
}

/**
 * @brief Processor UI
 * 
 * @return int 
 */
int chooseProcessor() {
	int p;
	std::cout << "SELECT A PROCESSOR" << std::endl;
  std::cout << "1. Normalize" << std::endl;
  std::cout << "2. Echo" << std::endl;
  std::cout << "3. Gain adjustment" <<std::endl;
  std::cout << "0. Return to start" <<std::endl;
	std::cin >> p;
	if (0 > p || p > 3) {
		return 0;
	}
	return p;
}

/**
 * @brief Reads the inputfile and creates a switch case for the user to input onto the UI
 * 
 * @return int 
 */
int main() {
	int start;
	do {
		start = startMenu();
		if (start == 0) {
			return 0;
		}
		std::string inputFilename;
		std::cout << "Input Filename\n";
		std::cin >> inputFilename;
		Wav wav;
		if (!wav.readFile(inputFilename)) {
			continue;
		}
		wav.printMetadata();
		int processor = chooseProcessor();
		if (processor != 0) {
			std::string outputFilename;
			std::cout << "Output Filename\n";
			std::cin >> outputFilename;
			outputFilename += ".wav";
			if (outputFilename.compare(inputFilename) == 0) {
				std::cout << "Output filename must be different\n";
				continue;
			}

			wav.copyFile(outputFilename);
			wav.readFile(outputFilename);
			float f;
			float s;
			switch (processor) {
				case 1:
					wav.normal();
					break;
				case 2:
					std::cout << "Input factor of echoes\n";
					std::cin >> f;
					while (0 > f || f > 1) {
						std::cout << "Factor must be between 0 and 1\n";
						std::cin >> f;
					}
					std::cout << "Input delay in seconds\n";
					std::cin >> s;
					while (0 > s) {
						std::cout << "Seconds must be positive\n";
						std::cin >> s;
					}
					wav.echo(f, s);
					break;
				case 3:
					std::cout << "Input gain adjustment factor\n";
					std::cin >> f;
					while (0 > f) {
						std::cout << "Factor must be positive\n";
						std::cin >> f;
					}
					wav.gain(f);
					break;
			}
			wav.writeFile();
		}
	}
	while (start != 0);
} 