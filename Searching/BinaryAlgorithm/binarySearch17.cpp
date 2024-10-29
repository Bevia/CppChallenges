#include <iostream>
#include <vector>
#include <optional>

// std::optional is a C++17 feature that allows you to represent a value that may or may not exist.
// const std::vector<int>& arr is a constant reference to a vector of integers.
// Using a reference (&) instead of passing by value avoids copying the vector, making the function more efficient, especially with large arrays
std::optional<int> binary_search(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return std::nullopt;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;

    auto result = binary_search(arr, target);
    if (result) {
        std::cout << "Found at index: " << *result << '\n';
    } else {
        std::cout << "Not found\n";
    }

    return 0;
}