// palindrome.cpp
#include "palindrome.h"
#include <cctype> // for std::tolower

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        while (!std::isalnum(str[left]) && left < right) {
            left++;
        }
        while (!std::isalnum(str[right]) && left < right) {
            right--;
        }
        if (std::tolower(str[left]) != std::tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
