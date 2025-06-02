#include <iostream> // Required for input/output operations (e.g., std::cout, std::endl)
#include <vector>   // Required for std::vector, which is a dynamic array to store matches
#include <string>   // Required for std::string, to work with strings

// Function to find all starting indices where the pattern matches in the array_string
std::vector<int> findSlidingWindowMatches(const std::string& array_string, const std::string& pattern_string) {
    std::vector<int> matches; // Create a vector to store the starting indices of matches

    // Get the lengths of the array and pattern strings
    int n = array_string.length();
    int m = pattern_string.length();

    // If the pattern is longer than the array, no match is possible.
    if (m > n) {
        std::cout << "Pattern is longer than the array string. No matches possible." << std::endl;
        return matches; // Return an empty vector
    }

    // Iterate through the array string, moving the window one character at a time.
    // The loop runs from index 0 up to n - m (inclusive) because the window
    // needs to fit entirely within the array.
    for (int i = 0; i <= n - m; ++i) {
        // Extract the current substring (window) from the array_string.
        // In C++, std::string::substr(pos, len) is used to get a substring.
        std::string current_window = array_string.substr(i, m);

        // Compare the current window with the pattern string.
        if (current_window == pattern_string) {
            // If they match, add the starting index of the match to the results list.
            matches.push_back(i); // Add the index to the vector
        }
    }

    return matches; // Return the vector of matching indices
}

int main() {
    // Example Usage:
    std::string array1 = "abbababbaaba";
    std::string k1 = "bab";

    std::cout << "Array: " << array1 << std::endl;
    std::cout << "Pattern: " << k1 << std::endl;

    // Find the matches
    std::vector<int> matching_indices1 = findSlidingWindowMatches(array1, k1);

    if (!matching_indices1.empty()) { // Check if the vector is not empty
        std::cout << "Pattern '" << k1 << "' found at starting indices: [";
        for (size_t i = 0; i < matching_indices1.size(); ++i) {
            std::cout << matching_indices1[i];
            if (i < matching_indices1.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;

        for (int index : matching_indices1) { // Enhanced for loop for convenience
            std::cout << "  Match found at index " << index << ": '" << array1.substr(index, k1.length()) << "'" << std::endl;
        }
    } else {
        std::cout << "Pattern '" << k1 << "' not found in the array." << std::endl;
    }

    std::cout << "\n----------------------------------------\n" << std::endl;

    std::string array2 = "abbababbaabbabbaa";
    std::string k2 = "bbabb";

    std::cout << "Array: " << array2 << std::endl;
    std::cout << "Pattern: " << k2 << std::endl;

    // Find the matches
    std::vector<int> matching_indices2 = findSlidingWindowMatches(array2, k2);

    if (!matching_indices2.empty()) {
        std::cout << "Pattern '" << k2 << "' found at starting indices: [";
        for (size_t i = 0; i < matching_indices2.size(); ++i) {
            std::cout << matching_indices2[i];
            if (i < matching_indices2.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;

        for (int index : matching_indices2) {
            std::cout << "  Match found at index " << index << ": '" << array2.substr(index, k2.length()) << "'" << std::endl;
        }
    } else {
        std::cout << "Pattern '" << k2 << "' not found in the array." << std::endl;
    }

    return 0; // Indicate successful execution
}