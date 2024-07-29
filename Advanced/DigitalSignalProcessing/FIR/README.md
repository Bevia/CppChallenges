## How to run:
    g++ ./Advanced/DigitalSignalProcessing/FIR/fir.cpp ./Advanced/DigitalSignalProcessing/FIR/fir.cpp -o fir 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Advanced/DigitalSignalProcessing/FIR/fir.cpp -o ./Advanced/DigitalSignalProcessing/FIR/fir.cpp -o fir 
#### To run the program, use this command:
    ./fir

### compile the FTTW3 library...find the route of the lib and do the following:
g++ -std=c++11 -o fir ./Advanced/DigitalSignalProcessing/FIR/fir.cpp -lfftw3 -L/opt/homebrew/Cellar/fftw/3.3.10_1/lib/ -I/opt/homebrew/Cellar/fftw/3.3.10_1/include/

g++ -std=c++11 -L/opt/homebrew/Cellar/fftw/3.3.10_1/lib/ -I/opt/homebrew/Cellar/fftw/3.3.10_1/include -lfftw3 -lm -o fir ./Advanced/DigitalSignalProcessing/FIR/fir.cpp

### my path to fftw
/opt/homebrew/Cellar/fftw/3.3.10_1/include

### path to python:
python3 ./Advanced/DigitalSignalProcessing/FIR/fir_response.py


### Testing opening python file from C++
 g++ -std=c++11 ./Advanced/DigitalSignalProcessing/FIR/read_python_script.cpp -o ./Advanced/DigitalSignalProcessing/FIR/read_python_script.cpp -o testing 
 ./testing

 ## Theory

Digital Signal Processing (DSP) Finite Impulse Response (FIR) filters are a type of digital filter used to manipulate or modify signals in various ways, such as removing noise, shaping signals, or extracting useful information from them. FIR filters have a finite duration of response to an impulse input, meaning they settle to zero in a finite amount of time.

### Key Characteristics:
1. **Finite Duration Response**: The output response to an impulse input is finite and lasts for exactly \( N \) samples, where \( N \) is the number of filter coefficients.
2. **Linearity and Time-Invariance**: FIR filters are linear and time-invariant, meaning their behavior does not change over time and they adhere to the principle of superposition.
3. **No Feedback**: FIR filters are non-recursive, meaning the output depends only on the current and past input values, not on past output values. This eliminates stability issues commonly associated with recursive filters.

### Design and Implementation:
1. **Filter Coefficients**: FIR filters are defined by a set of coefficients \( h[n] \), where \( n \) ranges from 0 to \( N-1 \). These coefficients determine the filter's impulse response.
2. **Convolution Operation**: The output \( y[n] \) of an FIR filter is obtained by convolving the input signal \( x[n] \) with the filter coefficients \( h[n] \). Mathematically, this is expressed as:
   \[
   y[n] = \sum_{k=0}^{N-1} h[k] \cdot x[n-k]
   \]
3. **Windowing Techniques**: Designing FIR filters often involves windowing techniques to control the trade-off between main lobe width and side lobe levels in the filter's frequency response.

### Advantages:
1. **Stability**: Since FIR filters have no feedback mechanism, they are inherently stable.
2. **Linear Phase Response**: FIR filters can be designed to have a linear phase response, which means that all frequency components of the input signal are delayed by the same amount, preserving the wave shape of the signal.
3. **Flexibility**: They can be designed to approximate virtually any frequency response.

### Applications:
1. **Noise Reduction**: FIR filters can remove unwanted noise from signals.
2. **Signal Separation**: They can separate different frequency components of a signal, such as in audio equalization.
3. **Data Smoothing**: FIR filters can smooth data to reduce fluctuations and highlight trends.

In summary, FIR filters are a fundamental tool in digital signal processing, valued for their stability, predictable behavior, and design flexibility.
