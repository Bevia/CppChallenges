Explanation

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