#include <iostream>
#include <cstring> // for std::strncpy
#include <string>

void safeFunction(const std::string& userInput) {
    char buffer[10];
    std::strncpy(buffer, userInput.c_str(), sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
    std::cout << "Buffer content: " << buffer << std::endl;
}

void saferFunction(const std::string& userInput) {
    std::string buffer = userInput.substr(0, 9); // Safely limit the length
    std::cout << "Buffer content: " << buffer << std::endl;
}

int main() {
    const std::string longInput = "This input is definitely too long!";
    
    // Using strncpy
    std::cout << "Using strncpy:" << std::endl;
    safeFunction(longInput);
    
    // Using std::string
    std::cout << "Using std::string:" << std::endl;
    saferFunction(longInput);
    
    return 0;
}
