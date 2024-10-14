## Binary Search Algorithm

Binary search is an efficient algorithm for finding a target value in a sorted array. It works by repeatedly dividing the search interval in half, reducing the size of the problem in each step. Here’s how it works:

	1.	Start: Look at the middle element of the sorted array.
	2.	Comparison: If the middle element matches the target, you’re done.
	3.	Divide: If the target is less than the middle element, search the left half of the array; if it’s greater, search the right half.
	4.	Repeat: Continue this process until the target is found or the search space is empty.

The time complexity of binary search is O(log n), which is much faster than linear search (O(n)) for large datasets, but it requires the input array to be sorted.

This is a fundamental algorithm used in many applications, such as finding elements in databases, search engines, and other optimized search processes.

## Explanation of code:

	1.	Array Setup: A sorted vector arr is created with some sample integers.
	2.	Standard Library Binary Search: std::binary_search is used to check if the target value exists in the array.
	3.	Manual Binary Search: A custom binarySearch function is implemented to perform binary search without using the standard library.

Key Notes:

	•	Time Complexity: Both the manual and std::binary_search approaches have a time complexity of O(log n).
	•	Overflow Prevention: The formula mid = low + (high - low) / 2 is used to prevent overflow in cases where low + high might exceed the maximum value of an integer.