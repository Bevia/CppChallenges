#include <iostream>
#include <unordered_map>

int fibonacci(int n, std::unordered_map<int, int>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 10; // Example value
    std::unordered_map<int, int> memo;
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n, memo) << std::endl;
    return 0;
}