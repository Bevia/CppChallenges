#include <iostream>

// Non-tail-recursive factorial function with debug output
int factorial_non_TCO(int n, int depth) {
    std::cout << "Non-TCO Call Depth: " << depth << ", n: " << n << std::endl;
    if (n <= 1) {
        return 1;
    }
    return n * factorial_non_TCO(n - 1, depth + 1);
}

// Tail-recursive helper function with debug output
int factorialHelper(int n, int acc, int depth) {
    std::cout << "TCO Call Depth: " << depth << ", n: " << n << ", acc: " << acc << std::endl;
    if (n <= 1) {
        return acc;
    }
    return factorialHelper(n - 1, n * acc, depth + 1);
}

// Tail-recursive factorial function
int factorial_TCO(int n) {
    return factorialHelper(n, 1, 1);
}

int main() {
    int number = 5;
    std::cout << "Factorial (TCO) of " << number << " is " << factorial_TCO(number) << std::endl;
    std::cout << "Factorial (Non-TCO) of " << number << " is " << factorial_non_TCO(number, 1) << std::endl;
    return 0;
}
