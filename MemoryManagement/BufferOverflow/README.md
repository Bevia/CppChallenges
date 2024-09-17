## How to run:
    g++ ./MemoryManagement/BufferOverflow/bufferoverflow.cpp ./MemoryManagement/BufferOverflow/bufferoverflow.cpp -o bufferoverflow

    g++ ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp -o bufferoverflowhandeling 

### To enable C++11, use the following command:
    g++ -std=c++11 ./MemoryManagement/BufferOverflow/bufferoverflow.cpp -o ./MemoryManagement/BufferOverflow/bufferoverflow.cpp -o bufferoverflow

    g++ -std=c++11 ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp -o ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp -o bufferoverflowhandeling

#### To run the program, use this command:
    ./bufferoverflow
    ./bufferoverflowhandeling

## Buffer Overflow Theory

A buffer overflow occurs when data exceeds the boundaries of a buffer, allowing it to overwrite adjacent memory. This can lead to undefined behavior, crashes, or security vulnerabilities. Despite improvements in modern C++ and compiler checks, buffer overflows can still occur if not carefully handled.

In this bufferoverflow.cpp example, std::strcpy copies the entire userInput string into buffer without checking if buffer has enough space to hold the input. If the input string is longer than the buffer, it will overflow, causing undefined behavior.

Fixing the Buffer Overflow with bufferoverflowhandeling.cpp

To prevent buffer overflow, use safe functions like std::strncpy or consider using std::string:
In the safeFunction, std::strncpy is used to copy only as much data as the buffer can hold, and we ensure null-termination. The saferFunction uses std::string to avoid raw buffer manipulation, which is a safer and more idiomatic approach in modern C++.
