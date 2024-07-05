Mutex

A mutex (short for "mutual exclusion") is a synchronization primitive that is used to prevent multiple threads from accessing a shared resource simultaneously. In other words, it ensures that only one thread can own the mutex and thus access the shared resource at a time. Mutexes help avoid race conditions where the outcome depends on the sequence or timing of uncontrollable events.

No, mutexes and locks are not the same, though they are closely related. Let's clarify the distinction:
Mutex

A mutex (short for "mutual exclusion") is a synchronization primitive that is used to prevent multiple threads from accessing a shared resource simultaneously. In other words, it ensures that only one thread can own the mutex and thus access the shared resource at a time. Mutexes help avoid race conditions where the outcome depends on the sequence or timing of uncontrollable events.

In C++, the std::mutex class represents a mutex.
Locks

A lock is a mechanism that is used to acquire and release the mutex. The lock is responsible for managing the state of the mutex, ensuring that the mutex is acquired when a thread enters the critical section and released when the thread leaves the critical section. In modern C++, the standard library provides classes such as std::lock_guard and std::unique_lock to manage mutexes.

### to make it run:
g++ ./Multithreading/Mutexes/mutex.cpp ./Multithreading/Mutexes/mutex.cpp -o mutex 
### To enable C++11, use the following command:
g++ -std=c++11 ./Multithreading/Mutexes/mutex.cpp -o ./Multithreading/Mutexes/mutex.cpp -o mutex
### To run the program, use this command:
./mutex