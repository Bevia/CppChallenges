#include <iostream>
#include <cstdint>

// Function to count set bits using bitwise operations
int countSetBits(uint32_t n) {
    int count = 0;
    while (n) {
        count += n & 1; // Check if the least significant bit is set
        n >>= 1;        // Right shift to check the next bit
    }
    return count;
}

int main() {
    uint32_t n = 13; // Example input
    std::cout << "The number of set bits in " << n << " is " 
              << countSetBits(n) << '\n';
    return 0;
}