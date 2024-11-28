
#include <vector>
#include <utility> // for std::pair
#include <iostream>
#include <algorithm> // for std::sort


std::vector<std::pair<int, int>> findMorePairs(const std::vector<int>& arr, int target) {
    std::vector<std::pair<int, int>> result;
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) {
            result.emplace_back(arr[left], arr[right]);
            ++left;
            --right;

            // Skip duplicate values for `left`
            while (left < right && arr[left] == arr[left - 1]) {
                ++left;
            }

            // Skip duplicate values for `right`
            while (left < right && arr[right] == arr[right + 1]) {
                --right;
            }
        } else if (currentSum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return result;
}

// Example usage
int main() {
    std::vector<int> arr = {1, 2, 3, 4, 4, 5, 6, 7};
    int target = 8;

    auto pairs = findMorePairs(arr, target);

    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ")\n";
    }

    return 0;
}