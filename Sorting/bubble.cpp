#include <iostream>
#include <vector>

//  to make it run:
//  g++ ./Sorting/bubble.cpp ./Sorting/bubble.cpp -o bubble 
//  To enable C++11, use the following command:
//  g++ -std=c++11 ./Sorting/bubble.cpp -o ./Sorting/bubble -o bubble
//  To run the program, use this command:
//  ./bubble

// Function to implement Bubble Sort
/*
The bubbleSort method is an implementation of the Bubble Sort algorithm. It takes in a reference to a std::vector<int> called arr, 
which represents the array to be sorted. The method sorts the array in ascending order.
as it has a time complexity of O(n^2).

*/
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size(); //It starts by initializing a variable n with the size of the input array arr. This will be used to control the number of iterations in the outer loop.
    bool swapped; //The method uses a boolean variable swapped to keep track of whether any elements were swapped during a pass through the array. It is initially set to false.
    for (int i = 0; i < n - 1; ++i) { //The outer loop runs n - 1 times. It iterates from i = 0 to i < n - 1. This loop controls the number of passes through the array.
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) { //Inside the outer loop, the inner loop runs from j = 0 to j < n - i - 1. This loop compares adjacent elements in the array and swaps them if they are in the wrong order.
            if (arr[j] > arr[j + 1]) { //If arr[j] is greater than arr[j + 1], it means that the elements are out of order. In that case, the std::swap function is used to swap the elements.
                std::swap(arr[j], arr[j + 1]); //After swapping, the swapped variable is set to true to indicate that a swap has occurred.
                swapped = true; //At the end of each pass through the inner loop, the swapped variable is checked. If no elements were swapped during the pass, it means that the array is already sorted, and there is no need to continue the sorting process. In that case, the break statement is used to exit the outer loop.
             //Finally, when the sorting process is complete, the array arr will be sorted in ascending order.
            }
        }
        //If no two elements were swapped in the inner loop, then the array is already sorted
        //The Bubble Sort algorithm works by repeatedly swapping adjacent elements if they are in the wrong order, gradually moving the larger elements towards the end of the array. It continues this process until the array is fully sorted. Although Bubble Sort is simple to understand, it is not the most efficient sorting algorithm, especially for large arrays, 
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
