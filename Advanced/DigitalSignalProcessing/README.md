## How to run:
    g++ ./Advanced/DigitalSignalProcessing/fir.cpp ./Advanced/DigitalSignalProcessing/fir.cpp -o fir 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Advanced/DigitalSignalProcessing/fir.cpp -o ./Advanced/DigitalSignalProcessing/fir.cpp -o fir 
#### To run the program, use this command:
    ./fir

### compile the FTTW3 library...find the route of the lib and do the following:
g++ -std=c++11 -o fir ./Advanced/DigitalSignalProcessing/fir.cpp -lfftw3 -L/opt/homebrew/Cellar/fftw/3.3.10_1/lib/ -I/opt/homebrew/Cellar/fftw/3.3.10_1/include

g++ -std=c++11 -L/opt/homebrew/Cellar/fftw/3.3.10_1/lib/ -I/opt/homebrew/Cellar/fftw/3.3.10_1/include -lfftw3 -lm -o fir ./Advanced/DigitalSignalProcessing/fir.cpp
