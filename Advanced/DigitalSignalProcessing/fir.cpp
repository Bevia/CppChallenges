#include <iostream>
#include <vector>
#include <cmath>
#include <fftw3.h>

using namespace std;

// Helper function to compute the sinc function
double sinc(double x) {
    if (x == 0.0) return 1.0;
    return sin(M_PI * x) / (M_PI * x);
}

int main() {
    // Specifications
    const int fs = 1000;   // Sampling frequency
    const int fc = 200;    // Cutoff frequency
    const int N = 21;      // Filter order + 1 (should be odd for symmetry)

    // Normalized cutoff frequency
    double omega_c = static_cast<double>(fc) / (fs / 2);

    // Compute ideal impulse response
    vector<double> h_d(N);
    int center = N / 2;
    for (int n = 0; n < N; ++n) {
        h_d[n] = omega_c * sinc(omega_c * (n - center));
    }

    // Apply Hamming window
    vector<double> w(N);
    for (int n = 0; n < N; ++n) {
        w[n] = 0.54 - 0.46 * cos(2 * M_PI * n / (N - 1));
    }

    vector<double> h(N);
    for (int n = 0; n < N; ++n) {
        h[n] = h_d[n] * w[n];
    }

    // Display impulse response
    cout << "Impulse Response:\n";
    for (const auto& coef : h) {
        cout << coef << endl;
    }

    // Compute frequency response using FFTW
    int fft_size = 1024;
    fftw_complex *in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fft_size);
    fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fft_size);
    fftw_plan p = fftw_plan_dft_1d(fft_size, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // Zero-padding and copying the filter coefficients
    for (int i = 0; i < fft_size; ++i) {
        if (i < N) {
            in[i][0] = h[i];
            in[i][1] = 0.0;
        } else {
            in[i][0] = 0.0;
            in[i][1] = 0.0;
        }
    }

    fftw_execute(p);

    // Compute magnitude of frequency response
    vector<double> magnitude(fft_size / 2);
    for (int i = 0; i < fft_size / 2; ++i) {
        magnitude[i] = 20 * log10(sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]));
    }

    // Display frequency response
    cout << "Frequency Response (dB):\n";
    for (const auto& mag : magnitude) {
        cout << mag << endl;
    }

    // Clean up FFTW
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    return 0;
}
