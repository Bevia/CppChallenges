#include <iostream>
#include <vector>

class MemoryBlock {
public:
    int size;
    int* data;

    MemoryBlock(int size) : size(size) {
        data = new int[size];
        std::cout << "Allocated block of size " << size << std::endl;
    }

    ~MemoryBlock() {
        delete[] data;
        std::cout << "Deallocated block of size " << size << std::endl;
    }
};

int main() {
    // Step 1: Allocate several blocks of memory
    std::vector<MemoryBlock*> blocks;

    blocks.push_back(new MemoryBlock(10)); // Allocate 10 integers
    blocks.push_back(new MemoryBlock(20)); // Allocate 20 integers
    blocks.push_back(new MemoryBlock(30)); // Allocate 30 integers

    // Step 2: Deallocate the middle block to create fragmentation
    delete blocks[1];
    blocks[1] = nullptr;

    // Step 3: Try to allocate a large block, this may fail if there's fragmentation
    try {
        MemoryBlock* largeBlock = new MemoryBlock(25); // Allocate 25 integers
        delete largeBlock;
    } catch (std::bad_alloc& e) {
        std::cout << "Failed to allocate large block: " << e.what() << std::endl;
    }

    // Cleanup remaining blocks
    for (auto block : blocks) {
        if (block) {
            delete block;
        }
    }

    return 0;
}
