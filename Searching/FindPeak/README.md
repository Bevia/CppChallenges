## How to run:
    g++ ./Searching/FindPeak/findPeak.cpp ./Searching/FindPeak/findPeak.cpp -o findPeak 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Searching/FindPeak/findPeak.cpp -o ./Searching/FindPeak/findPeak.cpp -o findPeak 
#### To run the program, use this command:
    ./findPeak

# Problem Statement:
Given an array of integers arr, a "peak" element is an element that is not smaller
than its neighbors. For corner elements, we need to consider only one neighbor.
Write a function that finds a peak element in the array. The function should have a time complexity of
𝑂(log⁡𝑛) where 𝑛 is the length of the array.
Output:
The function should return any peak element from the array. If the array contains
multiple peaks, return any one of them. If no peak exists (which should not happen for a valid input), return None.

--------

Here are several ways you can formulate an interview question based on the provided C++ code, 
ranging in difficulty and focus:

## Interview Questions for `find_peak`

**Core Question (Direct, Entry-Level):**

"You are given a C++ function `find_peak` that aims to find a peak element in a vector of integers.
A peak element is an element that is greater than or equal to its neighbors.
If the element is at an edge, it only needs to be greater than or equal to its single neighbor.

1.  **Explain the logic** of the `find_peak` function. How does it work?
2.  **Walk through an example** execution with the input `std::vector<int> arr = {1, 3, 20, 4, 21, 0, 12, 26, 19};` and explain what the function will return.
3.  **Analyze the time and space complexity** of this algorithm."

---

**Follow-up Questions (Intermediate - Advanced):**

* **Edge Cases & Improvements:**
    * "What happens if the input vector is empty? What if it has only one element? Does the current code handle these cases correctly?"
    * "Consider a scenario where there are multiple peak elements. Does this function guarantee finding a *specific* peak (e.g., the first, the largest)? If not, how could you modify it to find, say, the *largest* peak element?"
    * "Could you optimize the `find_peak` function further? For example, are there any redundant checks or ways to reduce the number of iterations in certain scenarios?"

* **Variations & Generalization:**
    * "Imagine the definition of a 'peak' changes. For instance, what if a peak needs to be strictly greater than its neighbors? How would you modify the code?"
    * "How would your approach change if the input was a 2D array (matrix) and you needed to find a peak element where an element is a peak if it's greater than or equal to all its 4 (or 8, if diagonals count) neighbors?"
    * "Can you think of a scenario where a peak element might not exist according to your current definition, and what would the function return in that case?"

* **Conceptual & Design:**
    * "Why is a binary search approach suitable for this problem?"
    * "What are the advantages and disadvantages of using an iterative approach (like the `while` loop here) versus a recursive approach for solving this problem?"
    * "If you were to write unit tests for this function, what are some key test cases you would include?"

* **Debugging & Error Handling (If you want to introduce a subtle bug):**
    * "Let's say a user reports that for `arr = {5, 4, 3, 2, 1}`, the function doesn't return `5` as a peak. Is there a flaw in the logic? If so, how would you fix it?" (Note: In the current code, `5` would be found as a peak, so you'd need to subtly change the question or the expected output if you want to make it a true debugging task).

---

**Example of a good prompt for a coding challenge:**

"**Problem Statement:**

You are tasked with implementing a function `find_peak` that takes a `std::vector<int>` as input and returns a 'peak' element. A peak element is defined as an element that is greater than or equal to its immediate neighbors. For elements at the edges of the vector, only the single existing neighbor needs to be considered.

Your solution should aim for optimal time complexity.

**Provided Code (as a starting point or for reference):**

```cpp
#include <iostream>
#include <vector>

int find_peak(const std::vector<int>& arr) {
    int n = arr.size();

    if (n == 0) return -1;
    if (n == 1) return arr[0];

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
            return arr[mid];
        } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // Return -1 if no peak is found
}

int main() {
    std::vector<int> arr = {1, 3, 20, 4, 21, 0, 12, 26, 19};
    int peak = find_peak(arr);
    if (peak != -1) {
        std::cout << "Peak element is " << peak << std::endl;
    } else {
        std::cout << "No peak element found" << std::endl;
    }
    return 0;
}
```

**Your Tasks:**

1.  **Analyze the provided `find_peak` function.** Explain its underlying algorithm and why it is effective.
2.  **Determine the time and space complexity** of the provided solution.
3.  **Consider the case where the input array is strictly decreasing** (e.g., `{5, 4, 3, 2, 1}`). What will the function return, and why? Is this behavior correct according to the peak definition?
4.  **Propose any potential improvements or alternative approaches** for this problem, considering efficiency and robustness."

---

When asking these questions, encourage the candidate to think out loud, explain their reasoning, and justify their choices. This provides valuable insight into their problem-solving skills, not just their ability to recall facts.