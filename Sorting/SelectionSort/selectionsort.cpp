#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

//  to make it run:
//  g++ ./Sorting/SelectionSort/selectionsort.cpp ./Sorting/SelectionSort/selectionsort.cpp -o selectionsort 
//  To enable C++11, use the following command:
//  g++ -std=c++11 ./Sorting/SelectionSort/selectionsort.cpp -o ./Sorting/SelectionSort/selectionsort -o selectionsort
//  To run the program, use this command:
//  ./selectionsort

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
