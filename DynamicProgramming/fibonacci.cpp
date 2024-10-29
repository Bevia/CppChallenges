#include <iostream>
#include <unordered_map>

class Fibonacci {
public:
    int getFibonacci(int n) {
        // Check if we already computed this value
        if (memo.find(n) != memo.end()) return memo[n];
        
        // Base cases
        if (n <= 1) return n;
        
        // Recursive case with memoization
        memo[n] = getFibonacci(n - 1) + getFibonacci(n - 2);
        return memo[n];
    }

private:
    std::unordered_map<int, int> memo;
};

int main() {
    Fibonacci fib;
    int n;
    std::cout << "Enter the position of the Fibonacci sequence: ";
    std::cin >> n;
    
    std::cout << "Fibonacci(" << n << ") = " << fib.getFibonacci(n) << std::endl;
    return 0;
}