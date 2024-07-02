#include <iostream>
#include <vector>
#include <cmath>
#include <fftw3.h>

// Constants
const int N = 1024; // Number of points in the interferogram
const double PI = 3.14159265358979323846;

// Function to simulate an interferogram
void generateInterferogram(std::vector<double>& interferogram) {
    for (int i = 0; i < N; ++i) {
        // Simulate a simple sinusoidal interferogram
        interferogram[i] = cos(2 * PI * i / N) + 0.5 * cos(4 * PI * i / N);
    }
}

// Function to perform FFT and obtain the spectrum
void performFFT(const std::vector<double>& interferogram, std::vector<double>& spectrum) {
    fftw_complex* in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    fftw_plan p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // Prepare input data for FFTW
    for (int i = 0; i < N; ++i) {
        in[i][0] = interferogram[i]; // Real part
        in[i][1] = 0.0;              // Imaginary part
    }

    // Execute FFT
    fftw_execute(p);

    // Calculate the magnitude of the spectrum
    for (int i = 0; i < N; ++i) {
        spectrum[i] = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
    }

    // Clean up
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}

int main() {
    // Generate interferogram
    std::vector<double> interferogram(N);
    generateInterferogram(interferogram);

    // Perform FFT to obtain spectrum
    std::vector<double> spectrum(N);
    performFFT(interferogram, spectrum);

    // Print spectrum (just first 10 values for brevity)
    std::cout << "Spectrum:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << spectrum[i] << std::endl;
    }

    return 0;
}