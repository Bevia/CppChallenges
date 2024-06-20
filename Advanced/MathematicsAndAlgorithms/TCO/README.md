## Theory
Tail Call Optimization (TCO) is an optimization technique used by some compilers to improve the efficiency of recursive function calls. 
In C++, it is particularly useful for recursive functions that call themselves as their last operation. 

TCO is the process of optimizing tail calls to avoid adding a new stack frame to the call stack. Instead of creating a new stack frame for the called function, the current function's stack frame is reused. This optimization is particularly important for recursive functions as it can convert the recursion into an iterative process, thereby preventing potential stack overflow and reducing memory usage.

### Benefits of TCO

    Reduced Memory Usage: By reusing the current function’s stack frame, TCO significantly reduces the amount of memory required for recursive calls.
    Preventing Stack Overflow: TCO helps in preventing stack overflow errors in deep recursion scenarios.
    Improved Performance: It reduces the overhead of function calls and can lead to better performance in terms of speed.

## How to run:
    g++ ./Advanced/MathematicsAndAlgorithms/TCO/tail_call_optimization.cpp ./Advanced/MathematicsAndAlgorithms/TCO/tail_call_optimization.cpp -o tail_call_optimization
### To enable C++11, use the following command:
    g++ -std=c++11 ./Advanced/MathematicsAndAlgorithms/TCO/tail_call_optimization.cpp -o ./Advanced/MathematicsAndAlgorithms/TCO/tail_call_optimization -o tail_call_optimization 
#### To run the program, use this command:
    ./tail_call_optimization