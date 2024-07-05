In modern C++, you can use the <mutex> library to manage multithreading locks. 

Locks

A lock is a mechanism that is used to acquire and release the mutex. The lock is responsible for managing the state of the mutex, ensuring that the mutex is acquired when a thread enters the critical section and released when the thread leaves the critical section. In modern C++, the standard library provides classes such as std::lock_guard and std::unique_lock to manage mutexes.

    std::lock_guard is a simple lock that acquires the mutex upon construction and releases it upon destruction. It is typically used in a scope-limited manner.
    std::unique_lock is a more flexible lock that allows for deferred locking, timed locking, and manual unlocking.

### to make it run:
g++ ./Multithreading/Locks/locks.cpp ./Multithreading/Locks/locks.cpp -o locks 
### To enable C++11, use the following command:
g++ -std=c++11 ./Multithreading/Locks/locks.cpp -o ./Multithreading/Locks/locks.cpp -o locks
### To run the program, use this command:
./locks