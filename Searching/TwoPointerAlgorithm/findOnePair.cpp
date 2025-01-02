#include <vector>
#include <optional> // For std::optional
#include <utility>  // For std::pair
#include <algorithm> // For std::sort

/*
If you only need to find the first matching pair, you can modify the function to return std::optional<std::pair<int, int>>. 
Here’s how:
*/

std::optional<std::pair<int, int>> findOnePair(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    // Ensure the array is sorted (if not already sorted)
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());

    while (left < right) {
        int currentSum = sortedArr[left] + sortedArr[right];
        if (currentSum == target) {
            return std::make_pair(sortedArr[left], sortedArr[right]);
        } else if (currentSum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return std::nullopt; // No matching pair found
}

// Example usage
#include <iostream>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 8;

    auto result = findOnePair(arr, target);

    if (result) {
        std::cout << "Pair found: (" << result->first << ", " << result->second << ")\n";
    } else {
        std::cout << "No pair found.\n";
    }

    return 0;
}