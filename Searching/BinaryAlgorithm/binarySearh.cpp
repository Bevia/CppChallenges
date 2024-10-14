#include <iostream>
#include <vector>
#include <algorithm> // for std::sort and std::binary_search

// Manual binary search function
bool binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // To avoid overflow

        if (arr[mid] == target) {
            return true; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }

    return false; // Target not found
}

int main() {
    // Example sorted array
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17};

    // Sorting the array (in case it's not sorted)
    std::sort(arr.begin(), arr.end());

    int target = 7;

    // Using the standard library's binary_search function
    if (std::binary_search(arr.begin(), arr.end(), target)) {
        std::cout << "Target found using std::binary_search.\n";
    } else {
        std::cout << "Target not found using std::binary_search.\n";
    }

    // Using the manually implemented binary search
    if (binarySearch(arr, target)) {
        std::cout << "Target found using manual binary search.\n";
    } else {
        std::cout << "Target not found using manual binary search.\n";
    }

    return 0;
}