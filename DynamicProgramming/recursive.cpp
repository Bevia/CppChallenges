#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// this case has time complexity of n^2, for instance for n = 5 calls we have 4 calls and for n = 6 we have 23 calls!
/*
For example:
	•	 n = 3 : 5 calls.
	•	 n = 4 : 9 calls.
	•	 n = 5 : 15 calls.
	•	 n = 6 : 29 calls.
*/

// the total number of calls is roughly proportional to  2^n 

int main() {
    int n = 10; // Example value
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}