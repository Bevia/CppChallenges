## Custom Mememory Allocaror 

### Theory

Implementing a custom memory allocator in C++ involves creating a system that manages memory allocation and deallocation 
according to specific requirements. A simple example can involve creating a fixed-size block allocator. 
This kind of allocator can be useful when you need to allocate many small objects of the same size frequently.

Here is a simple example of a custom memory allocator in modern C++:
Custom Memory Allocator

    Define the Allocator Class:
    This class will manage a fixed-size block of memory.

    Implement Allocation and Deallocation:
    The allocator will manage the allocation and deallocation of memory blocks within the fixed-size memory.

    Handle Out-of-Memory Situations:
    The allocator should handle cases where memory runs out.

    Explanation:

    Constructor (SimpleAllocator):
        Initializes the allocator with a fixed block size and number of blocks.
        Allocates a contiguous block of memory (memory).
        Initializes a vector (freeBlocks) to manage free memory blocks.

    Destructor (~SimpleAllocator):
        Deallocates the contiguous block of memory.

    Allocate (allocate):
        Allocates a block from the free blocks. If no blocks are free, it throws a std::bad_alloc exception.

    Deallocate (deallocate):
        Returns a block to the free blocks.

    Main Function:
        Demonstrates the allocation and deallocation of memory blocks.

This simple allocator can be extended to include more features, such as handling variable-sized blocks, memory pooling, 
or integrating with standard C++ containers. However, for educational purposes, this example provides a basic understanding 
of how custom memory allocation works.

## How to run:
    g++ ./Advanced/MathematicsAndAlgorithms/CMA/cma.cpp ./Advanced/MathematicsAndAlgorithms/CMA/cma.cpp -o cma 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Advanced/MathematicsAndAlgorithms/CMA/cma.cpp -o ./Advanced/MathematicsAndAlgorithms/CMA/cma.cpp -o cma 
#### To run the program, use this command:
    ./cma