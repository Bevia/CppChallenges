### Run wit C++11, use the following command:
    g++ -std=c++11 ./MemoryManagement/Fragmentation/fragmentation.cpp -o ./MemoryManagement/Fragmentation/fragmentation.cpp -o fragmentation

#### To run the program, use this command:
    ./fragmentation

## Memory Fragmentation Theory

In memory management, fragmentation can occur when free memory is broken into small, non-contiguous blocks over time, making it difficult to allocate large contiguous memory blocks even if the total free memory is sufficient.

### Fragmentation Theory

Allocate Blocks: We first allocate three blocks of memory of different sizes (10, 20, and 30 integers).

Deallocate a Block: We then deallocate the middle block (the block of 20 integers) to simulate memory fragmentation. This leaves a gap in memory.

Attempt Large Allocation: We try to allocate a large block (25 integers). If the memory is fragmented and there's no contiguous space of 25 integers available, this allocation might fail.

Cleanup: Finally, we clean up the remaining allocated blocks to avoid memory leaks.

In a real system, memory allocation failures due to fragmentation might not be immediately evident in a small example like this, but the principle shown here is that fragmentation can make it difficult to allocate large contiguous blocks of memory even if there's enough total free memory available.
