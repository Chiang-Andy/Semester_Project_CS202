audioprocessor: main.cpp wav.o Echo.o gainAdjustment.o normalization.o 
	g++ -o audioprocessor wav.o Echo.o gainAdjustment.o normalization.o main.cpp
Wav.o: wav.cpp wav.h
	g++ -c -std=c++11 wav.cpp
Echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp
GainAdjustment.o: gainAdjustment.cpp gainAdjustment.h
	g++ -c -std=c++11 GainAdjustment.cpp
Normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp
clean:
	rm *.o audioprocessor