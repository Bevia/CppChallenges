# Explanation

## Including necessary headers:
        #include <iostream> for input and output.
        #include <vector> for using the std::vector container.
        #include <algorithm> for using std::swap.

## selectionSort Function:
        Takes a reference to a vector of integers.
        Determines the size of the array n.
        Iterates through the array, finding the minimum element in the unsorted portion and swapping it with the first unsorted element.

## main Function:
        Creates a vector of integers arr.
        Prints the original array.
        Calls the selectionSort function to sort the array.
        Prints the sorted array.

## Characteristics

    Simple and easy to implement.
    Works by repeatedly finding the minimum element and placing it at the beginning.
    Time Complexity: O(n2)O(n2).

## This implementation is simple and utilizes modern C++ features like the std::vector container and std::swap function.

### to make it run:
g++ ./Sorting/SelectionSort/selectionsort.cpp ./Sorting/SelectionSort/selectionsort.cpp -o selectionsort 
### To enable C++11, use the following command:
g++ -std=c++11 ./Sorting/SelectionSort/selectionsort.cpp -o ./Sorting/SelectionSort/selectionsort -o selectionsort
### To run the program, use this command:
./selectionsort