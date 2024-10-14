## The two-pointer algorithm
The two-pointer algorithm is a common and efficient technique used to solve problems in arrays, linked lists, or strings that involve searching, comparing, or modifying elements. It uses two indices (or pointers) that move through the data structure in a systematic way to achieve the desired result.

Here’s a detailed explanation of how it works:

### Key Idea

The main idea of the two-pointer algorithm is to use two pointers that traverse the data structure from different directions, often meeting in the middle or stopping at certain conditions. The pointers can either:

	1.	Move towards each other (e.g., one from the beginning and one from the end).
	2.	Move at different speeds (e.g., a “slow” pointer and a “fast” pointer).

### Common Use Cases

	1.	Finding pairs that sum to a target: In a sorted array, one pointer starts at the beginning and the other at the end. By comparing the sum of the values at both pointers with the target, you can decide whether to move the left pointer forward (to increase the sum) or the right pointer backward (to decrease the sum).
	2.	Reversing an array/string: One pointer starts at the beginning, the other at the end. They swap elements as they move toward the center.
	3.	Removing duplicates from a sorted array: One pointer (the “slow” pointer) tracks where the next unique element should be placed, while the other pointer (the “fast” pointer) scans through the array for duplicates.
	4.	Finding the maximum area of a container (LeetCode problem “Container with Most Water”): Two pointers are placed at the ends of the array, representing the sides of a container. The goal is to maximize the area while moving the shorter side inward.
	5.	Cycle detection in linked lists (Floyd’s Tortoise and Hare algorithm): Two pointers move at different speeds (one faster than the other). If they meet, a cycle exists in the list.

Example: Finding a Pair with a Given Sum in a Sorted Array

Let’s walk through an example where you want to find two numbers in a sorted array that add up to a given target sum.

#### Problem:

	•	Given a sorted array nums = [1, 2, 4, 7, 11, 15] and a target sum of 15, find two numbers that add up to 15.

## Approach:

	1.	Initialize two pointers:
	•	left pointer starting at the beginning (index 0).
	•	right pointer starting at the end (index len(nums) - 1).
	2.	While the left pointer is less than the right pointer:
	•	Calculate the current sum of the values at both pointers: current_sum = nums[left] + nums[right].
	•	If current_sum == target, return the pair.
	•	If current_sum < target, move the left pointer to the right (to increase the sum).
	•	If current_sum > target, move the right pointer to the left (to decrease the sum).

### Summary

The two-pointer algorithm is versatile and is often used for optimization in problems involving:

	•	Searching for pairs (or triplets, quadruplets) that satisfy a condition.
	•	Reversing or sorting parts of a data structure.
	•	Detecting patterns in sequences, like cycles.