#include <iostream>
#include <vector>
#include <stdexcept>

class SimpleAllocator {
public:
    SimpleAllocator(size_t blockSize, size_t blockCount)
        : blockSize(blockSize), blockCount(blockCount) {
        memory = new char[blockSize * blockCount];
        freeBlocks.resize(blockCount);
        for (size_t i = 0; i < blockCount; ++i) {
            freeBlocks[i] = memory + i * blockSize;
        }
    }

    ~SimpleAllocator() {
        delete[] memory;
    }

    void* allocate() {
        if (freeBlocks.empty()) {
            throw std::bad_alloc();
        }
        void* block = freeBlocks.back();
        freeBlocks.pop_back();
        return block;
    }

    void deallocate(void* block) {
        freeBlocks.push_back(static_cast<char*>(block));
    }

private:
    size_t blockSize;
    size_t blockCount;
    char* memory;
    std::vector<char*> freeBlocks;
};

int main() {
    const size_t blockSize = 32;
    const size_t blockCount = 10;

    SimpleAllocator allocator(blockSize, blockCount);

    std::vector<void*> blocks;
    try {
        for (size_t i = 0; i < blockCount; ++i) {
            void* block = allocator.allocate();
            blocks.push_back(block);
            std::cout << "Allocated block " << i << " at " << block << std::endl;
        }

        // Test deallocation
        for (void* block : blocks) {
            allocator.deallocate(block);
            std::cout << "Deallocated block at " << block << std::endl;
        }

        // Test reallocation
        for (size_t i = 0; i < blockCount; ++i) {
            void* block = allocator.allocate();
            std::cout << "Reallocated block " << i << " at " << block << std::endl;
        }
    } catch (const std::bad_alloc&) {
        std::cerr << "Out of memory!" << std::endl;
    }

    return 0;
}
