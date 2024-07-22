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

## General theory

The problems that smart pointers address in modern C++ are generally referred to as **memory management issues** or **resource management issues**. More specifically, they help solve problems such as:

1. **Memory Leaks**: Occur when dynamically allocated memory is not properly deallocated, leading to a gradual loss of available memory.
2. **Dangling Pointers**: Occur when an object is deleted but a pointer still points to the memory location where the object was, leading to undefined behavior if the pointer is dereferenced.
3. **Double Deletion**: Happens when an object is deleted more than once, which can cause program crashes and undefined behavior.
4. **Ownership Semantics**: Issues arise when it is unclear which part of the program is responsible for managing the lifetime of an object.
5. **Circular References**: Specifically addressed by `std::weak_ptr`, these occur when two or more objects reference each other via `std::shared_ptr`, preventing the reference count from reaching zero and thereby causing a memory leak.

By using smart pointers, you can effectively manage the lifetime of objects, ensure proper cleanup, and avoid the aforementioned problems. The automatic and deterministic resource management provided by smart pointers aligns with the RAII (Resource Acquisition Is Initialization) principle, which is a core concept in C++ for managing resources such as memory, file handles, and network connections.