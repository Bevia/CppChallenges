#include <iostream>
#include <vector>

int find_peak(const std::vector<int>& arr) {
    int n = arr.size();

    if (n == 0) return -1;
    if (n == 1) return arr[0];

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
            return arr[mid];
        } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // Return -1 if no peak is found
}

int main() {
    std::vector<int> arr = {1, 3, 20, 4, 21, 0, 12, 26, 19};
    int peak = find_peak(arr);
    if (peak != -1) {
        std::cout << "Peak element is " << peak << std::endl;
    } else {
        std::cout << "No peak element found" << std::endl;
    }
    return 0;
}
