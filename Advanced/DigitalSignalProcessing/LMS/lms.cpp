#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

// Function to compute the dot product of two vectors
double dotProduct(const std::vector<double>& a, const std::vector<double>& b) {
    return std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
}

// LMS algorithm
void lmsFilter(const std::vector<double>& input, const std::vector<double>& desired, std::vector<double>& output, double mu, int filterLength) {
    int n = input.size();
    std::vector<double> weights(filterLength, 0.0);
    std::vector<double> buffer(filterLength, 0.0);

    for (int i = 0; i < n; ++i) {
        // Shift buffer
        for (int j = filterLength - 1; j > 0; --j) {
            buffer[j] = buffer[j - 1];
        }
        buffer[0] = input[i];

        // Compute filter output
        double y = dotProduct(weights, buffer);

        // Compute error
        double error = desired[i] - y;

        // Update weights
        for (int j = 0; j < filterLength; ++j) {
            weights[j] += 2 * mu * error * buffer[j];
        }

        // Store output
        output[i] = y;
    }
}

int main() {
    // Example input signal
    std::vector<double> inputSignal = {0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};
    // Desired output signal (for demonstration purposes, let's assume it's a delayed version of the input)
    std::vector<double> desiredSignal = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1};

    // LMS parameters
    double mu = 0.01; // Step size
    int filterLength = 3; // Length of the adaptive filter

    // Output signal
    std::vector<double> outputSignal(inputSignal.size(), 0.0);

    // Apply LMS filter
    lmsFilter(inputSignal, desiredSignal, outputSignal, mu, filterLength);

    // Print results
    std::cout << "Input Signal:    ";
    for (const auto& val : inputSignal) std::cout << val << " ";
    std::cout << "\nDesired Signal:  ";
    for (const auto& val : desiredSignal) std::cout << val << " ";
    std::cout << "\nOutput Signal:   ";
    for (const auto& val : outputSignal) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
