#include <iostream>
#include <stack>
#include <stdexcept>

class MinElelemtFromStack {
public:
    void push(int value) {
        mainStack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    void pop() {
        if (mainStack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() const {
        if (mainStack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return mainStack.top();
    }

    int getMin() const {
        if (minStack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return minStack.top();
    }

private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
};

int main() {
    MinElelemtFromStack stack;
    stack.push(3);
    stack.push(5);
    std::cout << "Minimum element: " << stack.getMin() << std::endl;

    stack.push(2);
    stack.push(1);
    std::cout << "Minimum element: " << stack.getMin() << std::endl;

    stack.pop();
    std::cout << "Minimum element: " << stack.getMin() << std::endl;

    stack.pop();
    std::cout << "Minimum element: " << stack.getMin() << std::endl;

    return 0;
}
