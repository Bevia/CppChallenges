#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//  to make it run:
//  g++ ./Advanced/MathematicsAndAlgorithms/wavelet_transform.cpp ./Advanced/MathematicsAndAlgorithms/wavelet_transform.cpp -o wavelet_transform 
//  To enable C++11, use the following command:
//  g++ -std=c++11 ./Advanced/MathematicsAndAlgorithms/wavelet_transform.cpp -o ./Advanced/MathematicsAndAlgorithms/wavelet_transform -o wavelet_transform 
//  To run the program, use this command:
//  ./wavelet_transform

using namespace std;

// Perform the Haar wavelet transform on a vector of data
void haarWaveletTransform(vector<double>& data) {
    int n = data.size();
    vector<double> temp(n);

    while (n > 1) {
        n /= 2;

        for (int i = 0; i < n; ++i) {
            temp[i] = (data[2 * i] + data[2 * i + 1]) / sqrt(2.0);
            temp[n + i] = (data[2 * i] - data[2 * i + 1]) / sqrt(2.0);
        }

        for (int i = 0; i < 2 * n; ++i) {
            data[i] = temp[i];
        }
    }
}

// Helper function to print a vector
void printVector(const vector<double>& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Example data (must be a power of 2 for simplicity)
    vector<double> data = {4.0, 2.0, 1.0, 3.0, 5.0, 7.0, 6.0, 8.0};

    cout << "Original data: ";
    printVector(data);

    haarWaveletTransform(data);

    cout << "Transformed data: ";
    printVector(data);

    return 0;
}
