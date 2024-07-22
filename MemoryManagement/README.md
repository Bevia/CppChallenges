## Smart pointers in modern C++

Smart pointers in modern C++ are a powerful tool for managing the lifetime and ownership of dynamically allocated objects. 
The C++11 standard introduced three types of smart pointers: std::unique_ptr, std::shared_ptr, and std::weak_ptr. 
Here are examples demonstrating how each of these can be used:

### std::unique_ptr

A std::unique_ptr owns a dynamically allocated object exclusively. When the std::unique_ptr goes out of scope, it automatically deletes the object it owns.

### std::shared_ptr

A std::shared_ptr maintains a reference count of how many std::shared_ptr instances own the same object. The object is destroyed when the last std::shared_ptr owning it is destroyed or reset.

### std::weak_ptr

A std::weak_ptr is a non-owning reference to an object that is managed by a std::shared_ptr. It does not affect the reference count. A std::weak_ptr can be used to break circular references between std::shared_ptr instances.