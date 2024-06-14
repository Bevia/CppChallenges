// main.cpp
#include <iostream>
#include <string>
#include "palindrome.h" // Include the header file

//  to make it run:
//  g++ ./Strings/Palindrome/main.cpp ./Strings/Palindrome/palindrome.cpp -o palindrome 
//  ./palindrome

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome.\n";
    } else {
        std::cout << "The string is not a palindrome.\n";
    }

    return 0;
}
