#include <iostream> // Includes the iostream library, which provides input/output functionalities like std::cout (for printing to the console).
#include <vector>   // Includes the vector library, which provides the std::vector container for dynamic arrays.

// Function definition: find_peak
// - int: Specifies that the function returns an integer.
// - const std::vector<int>& arr:
//   - const: Indicates that the function will not modify the original vector 'arr'. This is good practice for read-only parameters.
//   - std::vector<int>: Specifies that the parameter is a vector of integers.
//   - &: Indicates that 'arr' is passed by reference. This avoids copying the entire vector, making the function more efficient, especially for large vectors.
int find_peak(const std::vector<int>& arr) {
    int n = arr.size(); // Gets the number of elements in the input vector 'arr' and stores it in the integer variable 'n'.

    if (n == 0) return -1; // Base case: If the vector is empty (n is 0), there's no peak, so return -1.
    if (n == 1) return arr[0]; // Base case: If the vector has only one element (n is 1), that element is by definition a peak, so return it.

    int low = 0; // Initializes 'low' to 0, representing the starting index of the search range.
    int high = n - 1; // Initializes 'high' to the last valid index of the vector, representing the end of the search range.

    // Start of the binary search loop. The loop continues as long as 'low' is less than or equal to 'high'.
    // This means there's still a valid search range (at least one element).
    while (low <= high) {
        int mid = (low + high) / 2; // Calculates the middle index of the current search range.
                                    // This is the core of the binary search: dividing the problem in half.

        // Check if the element at 'mid' is a peak.
        // A peak is defined as an element >= its left neighbor AND >= its right neighbor.
        // Special handling is needed for elements at the boundaries (mid == 0 or mid == n - 1).
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && // Check left neighbor:
            // (mid == 0): If 'mid' is the first element, it has no left neighbor, so this condition is true.
            // OR (arr[mid - 1] <= arr[mid]): If it has a left neighbor, check if the left neighbor is less than or equal to arr[mid].
            (mid == n - 1 || arr[mid + 1] <= arr[mid])) { // Check right neighbor:
            // (mid == n - 1): If 'mid' is the last element, it has no right neighbor, so this condition is true.
            // OR (arr[mid + 1] <= arr[mid]): If it has a right neighbor, check if the right neighbor is less than or equal to arr[mid].
            return arr[mid]; // If both conditions are true, arr[mid] is a peak, so return its value.

        } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            // If the element at 'mid' is NOT a peak because its left neighbor is GREATER (arr[mid-1] > arr[mid]),
            // it means we are on a downward slope moving left.
            // A peak *must* exist to the left of 'mid' (including mid-1) because the array goes up to the left.
            high = mid - 1; // So, we narrow our search range to the left half, excluding 'mid'.

        } else { // This 'else' branch handles the case where arr[mid + 1] > arr[mid].
            // If the element at 'mid' is NOT a peak because its right neighbor is GREATER (arr[mid+1] > arr[mid]),
            // it means we are on an upward slope moving right.
            // A peak *must* exist to the right of 'mid' (including mid+1) because the array goes up to the right.
            low = mid + 1; // So, we narrow our search range to the right half, excluding 'mid'.
        }
    }

    // If the loop finishes without finding a peak (which theoretically shouldn't happen for non-empty arrays
    // because a peak is guaranteed to exist in any array that has at least one element),
    // this line returns -1. This acts as a failsafe, though the logic ensures a peak is always found if n > 0.
    return -1;
}

// Main function: The entry point of the program.
int main() {
    // Declares and initializes a std::vector of integers with some sample values.
    std::vector<int> arr = {1, 3, 20, 4, 21, 0, 12, 26, 19};
    int peak = find_peak(arr); // Calls the find_peak function with the sample vector and stores the result in 'peak'.

    if (peak != -1) { // Checks if a peak was found (i.e., the return value is not -1).
        // If a peak was found, print its value to the console.
        // std::cout is the standard output stream.
        // << is the insertion operator, used to send data to the stream.
        // std::endl inserts a newline character and flushes the output buffer.
        std::cout << "Peak element is " << peak << std::endl;
    } else {
        // If no peak was found (which, again, shouldn't happen for this algorithm with non-empty arrays),
        // print a message indicating that.
        std::cout << "No peak element found" << std::endl;
    }
    return 0; // Indicates that the program executed successfully.
}