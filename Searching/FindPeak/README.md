## How to run:
    g++ ./Searching/FindPeak/findPeak.cpp ./Searching/FindPeak/findPeak.cpp -o findPeak 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Searching/FindPeak/findPeak.cpp -o ./Searching/FindPeak/findPeak.cpp -o findPeak 
#### To run the program, use this command:
    ./findPeak

# Problem Statement:
Given an array of integers arr, a "peak" element is an element that is not smaller
than its neighbors. For corner elements, we need to consider only one neighbor.
Write a function that finds a peak element in the array. The function should have a time complexity of
𝑂(log⁡𝑛) where 𝑛 is the length of the array.
Output:
The function should return any peak element from the array. If the array contains
multiple peaks, return any one of them. If no peak exists (which should not happen for a valid input), return None.