#include <thread>
#include <iostream>

int counter = 0; // shared variable

void increment_counter() {
    for (int i = 0; i < 1000; ++i) {
        counter++; // non-atomic increment operation
    }
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    t1.join();
    t2.join();

    std::cout << "Final counter value (without atomic operations): " << counter << std::endl;
    return 0;
}
