#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor\n"; }
    ~MyClass() { std::cout << "MyClass Destructor\n"; }
    void showMessage() { std::cout << "Hello from MyClass\n"; }
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr = ptr1;

    {
        std::shared_ptr<MyClass> ptr2 = weakPtr.lock();
        if (ptr2) {
            ptr2->showMessage();
            std::cout << "ptr2 use_count: " << ptr2.use_count() << "\n";
        }
    } // ptr2 goes out of scope, but the MyClass instance is not deleted

    if (std::shared_ptr<MyClass> ptr3 = weakPtr.lock()) {
        ptr3->showMessage();
    } else {
        std::cout << "ptr3 is null\n";
    }
    
    // ptr1 goes out of scope, and the MyClass instance is deleted

    return 0;
}
