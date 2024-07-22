#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor\n"; }
    ~MyClass() { std::cout << "MyClass Destructor\n"; }
    void showMessage() { std::cout << "Hello from MyClass\n"; }
};

int main() {
    {
        std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();
        ptr1->showMessage();
        
        // Transferring ownership
        std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
        if (!ptr1) {
            std::cout << "ptr1 is now null\n";
        }
        ptr2->showMessage();
    } // ptr2 goes out of scope, and the MyClass instance is deleted

    return 0;
}
