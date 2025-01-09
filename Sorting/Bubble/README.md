## Explanation

#include <iostream>: Includes the input-output stream library for console output.
#include <vector>: Includes the vector library for using std::vector.
bubbleSort function:
    Takes a reference to a std::vector<int> as its parameter.
    Iterates through the vector multiple times, comparing each pair of adjacent elements.
    Swaps elements if they are in the wrong order.
    If no swaps occur during an iteration, the algorithm breaks early as the array is already sorted.
main function:
    Initializes a vector with unsorted integers.
    Prints the unsorted array.
    Calls the bubbleSort function to sort the array.
    Prints the sorted array.

This example uses modern C++ features such as std::vector and range-based for loops to make the code more readable and easier to manage.

to make it run:
g++ ./Sorting/Bubble/bubble.cpp ./Sorting/Bubble/bubble.cpp -o bubble 
To enable C++11, use the following command:
g++ -std=c++11 ./Sorting/Bubble/bubble.cpp -o ./Sorting/Bubble/bubble -o bubble
To run the program, use this command:
./bubble

// Function to implement Bubble Sort

The bubbleSort method is an implementation of the Bubble Sort algorithm. It takes in a reference to a std::vector<int> called arr, 
which represents the array to be sorted. The method sorts the array in ascending order.
as it has a time complexity of O(n^2).

