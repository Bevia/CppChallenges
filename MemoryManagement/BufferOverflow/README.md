## How to run:
    g++ ./MemoryManagement/BufferOverflow/bufferoverflow.cpp ./MemoryManagement/BufferOverflow/bufferoverflow.cpp -o bufferoverflow

    g++ ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp -o bufferoverflowhandeling 

### To enable C++11, use the following command:
    g++ -std=c++11 ./MemoryManagement/BufferOverflow/bufferoverflow.cpp -o ./MemoryManagement/BufferOverflow/bufferoverflow.cpp -o bufferoverflow

    g++ -std=c++11 ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp -o ./MemoryManagement/BufferOverflow/bufferoverflowhandeling.cpp -o bufferoverflowhandeling

#### To run the program, use this command:
    ./bufferoverflow
    ./bufferoverflowhandeling

## Theory

A buffer overflow occurs when data exceeds the boundaries of a buffer, allowing it to overwrite adjacent memory. This can lead to undefined behavior, crashes, or security vulnerabilities. Despite improvements in modern C++ and compiler checks, buffer overflows can still occur if not carefully handled.

