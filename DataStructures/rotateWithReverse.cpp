#include <iostream>
#include <vector>
#include <algorithm> // for reverse()

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k > n

    std::reverse(nums.begin(), nums.end());       // Reverse the entire array
    std::reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
    std::reverse(nums.begin() + k, nums.end());   // Reverse the remaining elements
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}