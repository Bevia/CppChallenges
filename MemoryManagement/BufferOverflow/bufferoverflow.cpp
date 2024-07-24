#include <iostream>
#include <cstring> // for std::strcpy

void vulnerableFunction(const char* userInput) {
    char buffer[10];
    std::strcpy(buffer, userInput); // Potential buffer overflow
    std::cout << "Buffer content: " << buffer << std::endl;
}

int main() {
    // This input is longer than the buffer size
    const char* longInput = "This input is definitely too long!";
    vulnerableFunction(longInput);
    return 0;
}
