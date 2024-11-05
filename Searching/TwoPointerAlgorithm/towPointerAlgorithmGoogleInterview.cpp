#include <iostream>
#include <vector>
#include <unordered_set>

/*
To test this function with the two-pointer technique, 
you’ll need to call it in a main function with the specified nums array and target value.

However, the two-pointer technique usually works with sorted arrays, 
and your implementation is using a hash set. This means that even if 
the input array isn’t sorted, it will still work as long as the pair exists.
*/

// Function to check if there's a pair with the given sum
bool hasPairWithSum(const std::vector<int>& data, int sum) {
    std::unordered_set<int> comp;

    for (int value : data) {
        if (comp.find(value) != comp.end()) {
            return true;
        }
        comp.insert(sum - value);
    }
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 4, 7, 11, 15};
    int target = 13;

    if (hasPairWithSum(nums, target)) {
        std::cout << "Pair with sum " << target << " exists." << std::endl;
    } else {
        std::cout << "No pair with sum " << target << " exists." << std::endl;
    }

    return 0;
}