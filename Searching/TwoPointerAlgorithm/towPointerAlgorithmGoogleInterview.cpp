//#include <iostream>
//#include <vector>
//#include <unordered_set>

/*
To test this function with the two-pointer technique, 
you’ll need to call it in a main function with the specified nums array and target value.

However, the two-pointer technique usually works with sorted arrays, 
and your implementation is using a hash set. This means that even if 
the input array isn’t sorted, it will still work as long as the pair exists.
*/


#include <iostream>
#include <vector>
#include <unordered_set>  //using a hash set
#include <utility> // For std::pair

// Function to find and return the pair of numbers that add up to the sum
std::pair<int, int> findPairWithSum(const std::vector<int>& data, int sum) {
    std::unordered_set<int> comp;

    for (int value : data) {
        int complement = sum - value;
        if (comp.find(value) != comp.end()) {
            return {value, complement};  // Return the pair as soon as it's found
        }
        comp.insert(complement);
    }
    return {};  // Return an empty pair if no such pair exists
}

int main() {
    std::vector<int> nums = {1, 2, 4, 7, 11, 15};
    int target = 13;

    std::pair<int, int> result = findPairWithSum(nums, target);
    if (result != std::pair<int, int>{}) {  // Check if the result is not empty
        std::cout << "Pair with sum " << target << " found: " 
        << result.first << " and " << result.second << std::endl;
    } else {
        std::cout << "No pair with sum " << target << " found." << std::endl;
    }

    return 0;
}

// Function to check if there's a pair with the given sum
// bool hasPairWithSum(const std::vector<int>& data, int sum) {
//     std::unordered_set<int> comp;

//     for (int value : data) {
//         if (comp.find(value) != comp.end()) {
//             return true;
//         }
//         comp.insert(sum - value);
//     }
//     return false;
// }

// int main() {
//     std::vector<int> nums = {1, 2, 4, 7, 11, 15};
//     int target = 13;

//     if (hasPairWithSum(nums, target)) {
//         std::cout << "Pair with sum " << target << " exists." << std::endl;
//     } else {
//         std::cout << "No pair with sum " << target << " exists." << std::endl;
//     }

//     return 0;
// }