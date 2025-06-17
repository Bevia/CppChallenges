## Characteristics 

    Efficient for small or nearly sorted datasets.
    Builds the final sorted array one item at a time.
    Time Complexity: O(n2)O(n2) in the worst case, O(n)O(n) in the best case (when the array is already sorted).


to make it run:
g++ ./Sorting/InsertionSort/insertionSort.cpp ./Sorting/InsertionSort/insertionSort.cpp -o insertionSort 
To enable C++11, use the following command:
g++ -std=c++11 ./Sorting/InsertionSort/insertionSort.cpp -o ./Sorting/InsertionSort/insertionSort -o insertionSort
To run the program, use this command:
./insertionSort