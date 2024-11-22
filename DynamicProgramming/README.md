## How to run:
    g++ ./DynamicProgramming/fibonacci.cpp ./DynamicProgramming/fibonacci.cpp -o fibonacci 
### To enable C++11, use the following command:
    g++ -std=c++11 ./DynamicProgramming/fibonacci.cpp -o ./DynamicProgramming/fibonacci.cpp -o fibonacci 
    g++ -std=c++11 ./DynamicProgramming/lcs.cpp -o ./DynamicProgramming/lcs.cpp -o lcs 
#### To run the program, use this command:
    ./fibonacci
    ./lcs

### Theory
how to implement the Fibonacci sequence in modern C++ using different methods: 
a naive recursive approach  (This is a simple recursive implementation, but it has exponential time complexity O(2^n), which makes it inefficient for larger values of n)
memoization (This approach has a time complexity of O(n) and avoids recomputation by storing intermediate results.), and 
iterative approach with space optimization (This approach has a time complexity of O(n) and space complexity of O(1) because it only stores the last two Fibonacci numbers at any given time.) and
Modern C++ Lambda


### Summary:
Try to follow in this order to understand progression:

1. 	Naive Recursive: Simple but inefficient due to redundant calculations.
2.	Memoization: Stores previously calculated results, improving efficiency to O(n).
3.	Iterative: Space-optimized version with O(1) space complexity.
4.	Modern C++ Lambda: Compact, elegant solution leveraging lambdas and memoization.

