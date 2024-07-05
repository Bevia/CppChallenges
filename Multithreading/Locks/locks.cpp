#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx; // Mutex for critical section
int shared_counter = 0; // Shared resource

void increment_counter(int id, int num_iterations) {
    for (int i = 0; i < num_iterations; ++i) {
        // Lock the mutex before modifying the shared resource
        std::lock_guard<std::mutex> lock(mtx);
        ++shared_counter;
        std::cout << "Thread " << id << " incremented counter to " << shared_counter << std::endl;
        // Mutex is automatically released when lock goes out of scope
    }
}

int main() {
    const int num_threads = 5;
    const int num_iterations = 10;
    std::vector<std::thread> threads;

    // Create multiple threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(increment_counter, i, num_iterations));
    }

    // Wait for all threads to finish
    for (auto& th : threads) {
        th.join();
    }

    std::cout << "Final counter value: " << shared_counter << std::endl;
    return 0;
}
