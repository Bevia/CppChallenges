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
    {
        std::shared_ptr<MyClass> ptr2 = ptr1;
        std::cout << "ptr2 use_count: " << ptr2.use_count() << "\n";
        ptr2->showMessage();
    } // ptr2 goes out of scope, but the MyClass instance is not deleted

    std::cout << "ptr1 use_count: " << ptr1.use_count() << "\n";
    ptr1->showMessage();
    // ptr1 goes out of scope, and the MyClass instance is deleted

    return 0;
}
