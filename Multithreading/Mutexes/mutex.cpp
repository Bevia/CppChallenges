#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx; // Mutex to protect shared resource
int shared_counter = 0; // Shared resource

void increment_counter(int thread_id, int num_iterations) {
    for (int i = 0; i < num_iterations; ++i) {
        // Lock the mutex before modifying the shared resource
        mtx.lock();
        ++shared_counter;
        std::cout << "Thread " << thread_id << " incremented counter to " << shared_counter << std::endl;
        // Unlock the mutex after modifying the shared resource
        mtx.unlock();
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
