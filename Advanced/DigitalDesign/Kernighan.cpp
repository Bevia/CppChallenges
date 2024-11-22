#include <iostream>
#include <bitset>
#include <cstdint>

// Function to count set bits using std::bitset
// time complexity is O(log n)
int countSetBits(uint32_t n) {
    return std::bitset<32>(n).count();
}

int main() {
    uint32_t n = 13; // Example input
    std::cout << "The number of set bits in " << n 
              << " (binary: " << std::bitset<32>(n) << ") is " 
              << countSetBits(n) << '\n';
    return 0;
}