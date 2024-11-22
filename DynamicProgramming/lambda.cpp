#include <iostream>
#include <unordered_map>
#include <functional>

int main() {
    std::unordered_map<int, int> memo;
    
    // Lambda function for Fibonacci with memoization
    std::function<int(int)> fibonacci = [&](int n) -> int { // std::function<int(int)>: This is a type-erased wrapper for callable objects (like functions, lambdas). It’s used here because the lambda function calls itself recursively.
        if (n <= 1) return n;
        if (memo.find(n) != memo.end()) return memo[n];  // If n is already computed and stored in memo, return the cached result.
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);  // If n is not in the memo, compute it recursively. The result is then stored in memo[n] for future use.
    };
    
    int n = 10; // Example value
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}