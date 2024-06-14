#include <iostream>
#include "anagram.h"

//  to make it run:
//  g++ ./Strings/Anagram/main.cpp ./Strings/Anagram/anagram.cpp -o anagram 
//  ./anagram

int main() {
    // Example strings
    std::string str1 = "listen";
    std::string str2 = "silent";

    // Check if the strings are anagrams
    if (areAnagrams(str1, str2)) {
        std::cout << str1 << " and " << str2 << " are anagrams." << std::endl;
    } else {
        std::cout << str1 << " and " << str2 << " are not anagrams." << std::endl;
    }

    return 0;
}
