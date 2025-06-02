### Code explanation:

#include <iostream>: Provides standard input/output streams (like std::cout for printing to the console and std::endl for a newline).
#include <vector>: Provides the std::vector container, which is a dynamic array similar to Python's list.
#include <string>: Provides the std::string class, which handles string manipulation.
Function Definition:

Python: def find_sliding_window_matches(array_string, pattern_string):
C++: std::vector<int> findSlidingWindowMatches(const std::string& array_string, const std::string& pattern_string)
std::vector<int>: Specifies that the function returns a std::vector of integers.
const std::string&: This is a "constant reference" to a std::string.
const: Means the function won't modify the original array_string or pattern_string passed into it. This is good practice for read-only parameters.
&: Means it's a "reference." Instead of copying the entire string (which can be inefficient for large strings), it passes a reference to the original string in memory. This is similar to how Python handles arguments (passing references to objects).
Variable Declaration:

In C++, you must declare the type of a variable before using it (e.g., std::vector<int> matches;, int n = array_string.length();).
String Length:

Python: len(array_string)
C++: array_string.length() (or array_string.size(), which is synonymous)
Substrings (Slicing):

Python: array_string[i : i + m]
C++: array_string.substr(i, m)
substr() takes two arguments: the starting index and the length of the substring.
Appending to a List/Vector:

Python: matches.append(i)
C++: matches.push_back(i)
Printing to Console:

Python: print("...")
C++: std::cout << "..." << std::endl;
<<: The "insertion operator" is used to send data to std::cout.
std::endl: Inserts a newline character and flushes the output buffer. You can also use \n for just a newline, which is often more efficient.
Main Function (main()):

In C++, execution begins in the main function.
int main(): The main function returns an integer (typically 0 for success).
Checking if Vector is Empty:

Python: if matching_indices: (Python considers an empty list as False)
C++: if (!matching_indices.empty()) (The empty() method returns true if the vector is empty, so ! negates it.)
Looping through a Vector (for printing):

The example uses a traditional for loop with an index (for (size_t i = 0; i < matching_indices.size(); ++i)). size_t is an unsigned integer type suitable for sizes and counts.
It also shows an "enhanced for loop" (range-based for loop) for convenience, similar to Python's for element in list:: for (int index : matching_indices).