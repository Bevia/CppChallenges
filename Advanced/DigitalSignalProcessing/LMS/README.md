## How to run:
    g++ ./Advanced/DigitalSignalProcessing/LMS/lms.cpp ./Advanced/DigitalSignalProcessing/LMS/lms.cpp -o lms 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Advanced/DigitalSignalProcessing/LMS/lms.cpp -o ./Advanced/DigitalSignalProcessing/LMS/lms.cpp -o lms
#### To run the program, use this command:
    ./lms

### my path to fftw
/opt/homebrew/Cellar/fftw/3.3.10_1/include

### path to python:
#### about pandas:
https://github.com/pandas-dev/pandas
https://pandas.pydata.org/docs/
Installing pandas:
pip install pandas
or
brew install python

#### Running plotting file:
python3 ./Advanced/DigitalSignalProcessing/LMS/lms_plot.py

## About Least Mean Square
Explanation:

### dotProduct: 
A helper function to calculate the dot product of two vectors.
### lmsFilter: 
The main function implementing the LMS adaptive filter algorithm. It updates the filter weights based on the error between the desired signal and the filter output.
### main: 
An example usage of the LMS filter. It demonstrates how to use the lmsFilter function with a sample input and desired signals.

This program should give you a basic understanding of how the LMS algorithm works in the context of digital signal processing. The output of the program shows the input signal, desired signal, and the output signal after applying the LMS filter.