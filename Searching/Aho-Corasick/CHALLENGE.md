### **Coding Challenge: Implement Multi-Pattern String Searching**
Implement the Aho-Corasick algorithm to solve the following problem:

**Problem Statement**:  
Write a program that takes a list of keywords and searches for all occurrences of these keywords within a given text. The algorithm should efficiently handle mismatches using failure links, ensuring linear time complexity. The program should output the keywords found and their positions in the text.

---

### **Input Example**:
1. **Keywords**: `"he", "she", "his", "hers"`
2. **Text**: `"ushers"`

---

### **Expected Output**:
For the text `"ushers"`, output the positions where the keywords appear:
```
Found 'she' starting at index 2
Found 'he' starting at index 3
Found 'hers' starting at index 1
```

---

### **Requirements**:
1. Provide the implementation in **Python** *or* **C++**.
2. Use efficient data structures (trie and failure links).
3. Avoid using external libraries (write the algorithm manually).
4. Include comments in your code explaining each step.

---

### **Bonus Challenge**:
1. Modify your implementation to return the results in sorted order based on starting positions.
2. Handle edge cases such as overlapping keywords or special characters in the text.

---

This challenge provides a great opportunity for learners to understand and apply a complex algorithm while sharpening their coding skills. 