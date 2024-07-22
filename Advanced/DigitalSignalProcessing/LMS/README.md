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

### Running pandas example
python3 ./Advanced/DigitalSignalProcessing/LMS/pandas_example.py

## About Least Mean Square

How LMS Works in DSP

The LMS algorithm adjusts the coefficients of an adaptive filter to minimize the mean square error between the desired signal and the filter output. The main steps of the LMS algorithm are:

    Initialize the filter coefficients to small random values or zeros.
    For each input sample:
        Compute the filter output by taking the dot product of the input vector and the filter coefficients.
        Calculate the error as the difference between the desired signal and the filter output.
        Update the filter coefficients using the error and the input vector.

The coefficient update formula is given by:
w(n+1)=w(n)+2μe(n)x(n)w(n+1)=w(n)+2μe(n)x(n)
where:

    w(n)w(n) is the vector of filter coefficients at iteration nn.
    μμ is the step size (learning rate).
    e(n)e(n) is the error between the desired signal and the filter output at iteration nn.
    x(n)x(n) is the input vector at iteration nn.

Advantages of LMS

    Simplicity: The LMS algorithm is simple to implement and requires minimal computational resources.
    Adaptiveness: It can adapt to changing signal conditions in real-time, making it suitable for dynamic environments.
    Robustness: LMS algorithms are robust to variations in the signal statistics and can perform well in various applications.

Limitations of LMS

    Convergence Speed: The convergence speed of the LMS algorithm can be slow, especially for small step sizes.
    Steady-State Error: There may be a residual error in the steady state due to the noise in the error signal.
    Sensitivity to Step Size: The performance of the LMS algorithm is highly dependent on the choice of the step size. A large step size can lead to instability, while a small step size can result in slow convergence.

Conclusion

The LMS algorithm is a fundamental tool in DSP with a wide range of applications, particularly in adaptive filtering. Its simplicity and effectiveness make it a popular choice for real-time signal processing tasks, despite some limitations in convergence speed and sensitivity to parameter settings.

### dotProduct: 
A helper function to calculate the dot product of two vectors.
### lmsFilter: 
The main function implementing the LMS adaptive filter algorithm. It updates the filter weights based on the error between the desired signal and the filter output.
### main: 
An example usage of the LMS filter. It demonstrates how to use the lmsFilter function with a sample input and desired signals.

This program should give you a basic understanding of how the LMS algorithm works in the context of digital signal processing. The output of the program shows the input signal, desired signal, and the output signal after applying the LMS filter.