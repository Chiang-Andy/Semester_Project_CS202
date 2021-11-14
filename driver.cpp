//example, needs revision -andy nov 10
#include <iostream>
#include <string>
#include "wav.h"
#include "Processor.h"


const std::string testfile = "testing.wav";
const std::string limitfile = "limit.wav";
const std::string noisefile = "noise.wav";
int main() {
    Wav wav;
    wav.readFile(testfile);
    Processor *noisegate = new NoiseGate(10);
   	Processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("echos.wav");

    Wav wav;
    wav.readFile(testfile);
    Echo *echo = new echo(10);
   	echo->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("echos.wav");

    Wav wav;
    wav.readFile(testfile);
    Normalization *Normalization = new echo(10);
   	echo->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("echos.wav");


    return 0;
}


    Wav wav;
    wav.readFile(testfile);
    Processor *processor = new Normalization(10);
    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("Normalization.wav");

//    Follow the pattern above to generate the limit and noise files
//    using the filenames provided
