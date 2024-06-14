#include "anagram.h"
#include <algorithm>

// Function to check if two strings are anagrams
bool areAnagrams(const std::string& str1, const std::string& str2) {
    // If the lengths of the strings are not equal, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    // Create copies of the strings to sort them
    std::string sortedStr1 = str1;
    std::string sortedStr2 = str2;

    // Sort the strings
    std::sort(sortedStr1.begin(), sortedStr1.end());
    std::sort(sortedStr2.begin(), sortedStr2.end());

    // Compare the sorted strings
    return sortedStr1 == sortedStr2;
}
