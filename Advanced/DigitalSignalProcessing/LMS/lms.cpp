#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <fstream>

double dotProduct(const std::vector<double>& a, const std::vector<double>& b) {
    return std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
}

void lmsFilter(const std::vector<double>& input, const std::vector<double>& desired, std::vector<double>& output, double mu, int filterLength) {
    int n = input.size();
    std::vector<double> weights(filterLength, 0.0);
    std::vector<double> buffer(filterLength, 0.0);

    for (int i = 0; i < n; ++i) {
        for (int j = filterLength - 1; j > 0; --j) {
            buffer[j] = buffer[j - 1];
        }
        buffer[0] = input[i];

        double y = dotProduct(weights, buffer);
        double error = desired[i] - y;

        for (int j = 0; j < filterLength; ++j) {
            weights[j] += 2 * mu * error * buffer[j];
        }

        output[i] = y;
    }
}

int main() {
    std::vector<double> inputSignal = {0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};
    std::vector<double> desiredSignal = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1};

    double mu = 0.01;
    int filterLength = 3;

    std::vector<double> outputSignal(inputSignal.size(), 0.0);

    lmsFilter(inputSignal, desiredSignal, outputSignal, mu, filterLength);

    // Write results to a CSV file
    std::ofstream outFile("lms_results.csv");
    outFile << "Input,Desired,Output\n";
    for (size_t i = 0; i < inputSignal.size(); ++i) {
        outFile << inputSignal[i] << "," << desiredSignal[i] << "," << outputSignal[i] << "\n";
    }
    outFile.close();

    std::cout << "Results written to lms_results.csv" << std::endl;
    return 0;
}
