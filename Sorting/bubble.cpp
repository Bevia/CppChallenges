#include <iostream>
#include <vector>

//  to make it run:
//  g++ ./Sorting/bubble.cpp ./Sorting/bubble.cpp -o bubble 
//  To enable C++11, use the following command:
//  g++ -std=c++11 ./Sorting/bubble.cpp -o ./Sorting/bubble -o bubble
//  To run the program, use this command:
//  ./bubble

// Function to implement Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!swapped)
            break;
    }
}

int main() {
    // Initialize a vector with unsorted integers
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    // Print the unsorted array
    std::cout << "Unsorted array: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the array using Bubble Sort
    bubbleSort(arr);

    // Print the sorted array
    std::cout << "Sorted array: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
