#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter(0); // atomic variable

void increment_counter() {
    for (int i = 0; i < 1000; ++i) {
        counter.fetch_add(1); // atomic increment operation
    }
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}
