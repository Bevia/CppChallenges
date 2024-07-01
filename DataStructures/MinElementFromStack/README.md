## Explanation

### Class Definition (MinStack):
mainStack stores all the elements.
minStack keeps track of the minimum elements.

### Methods:
push(int value): Adds an element to both mainStack and, if appropriate, minStack.
pop(): Removes the top element from mainStack and minStack if the top elements match.
top() const: Returns the top element of mainStack.
getMin() const: Returns the top element of minStack, which is the current minimum.

### Main Function:
Demonstrates the functionality by pushing and popping elements from the stack and printing the minimum element at various stages.

This program uses modern C++ practices such as exception handling and encapsulation. 
The MinStack class provides a robust way to manage the stack and keep track of the minimum element efficiently.

### to make it run:
g++ ./DataStructures/MinElementFromStack/minelementfromstack.cpp ./DataStructures/MinElementFromStack/minelementfromstack.cpp -o minelementfromstack 
### To enable C++11, use the following command:
g++ -std=c++11 ./DataStructures/MinElementFromStack/minelementfromstack.cpp -o ./DataStructures/MinElementFromStack/minelementfromstack.cpp -o minelementfromstack 
### To run the program, use this command:
./minelementfromstack
