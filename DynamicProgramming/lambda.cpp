#include <iostream>
#include <unordered_map>
#include <functional>

int main() {
    std::unordered_map<int, int> memo;
    std::function<int(int)> fibonacci = [&](int n) -> int { 
        if (n <= 1) return n;
        if (memo.find(n) != memo.end()) return memo[n]; 
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);  
    };
    
    int n = 10; // Example value
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}