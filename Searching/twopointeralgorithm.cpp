#include <iostream>
#include <vector>
#include <optional>
#include <utility> // Required for std::pair

// Function to find the pair with the given sum using two pointers
std::optional<std::pair<int, int>> findPairWithSum(const std::vector<int>& nums, int target) {
    // Initialize two pointers
    int left = 0;
    int right = nums.size() - 1;
    
    // Loop until the two pointers meet
    while (left < right) {
        int current_sum = nums[left] + nums[right];
        
        if (current_sum == target) {
            // Return the pair if we found the target sum
            return std::make_pair(nums[left], nums[right]);
        }
        else if (current_sum < target) {
            // Move left pointer to the right to increase the sum
            ++left;
        }
        else {
            // Move right pointer to the left to decrease the sum
            --right;
        }
    }
    
    // Return empty optional if no pair is found
    return std::nullopt;
}

int main() {
    // Example input
    std::vector<int> nums = {1, 2, 4, 7, 11, 15};
    int target = 15;

    // Find the pair
    auto result = findPairWithSum(nums, target);

    // Output the result
    if (result) {
        std::cout << "Pair found: " << result->first << ", " << result->second << '\n';
    } else {
        std::cout << "No pair found.\n";
    }

    return 0;
}