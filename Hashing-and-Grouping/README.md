## Count Largest Group

You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.


Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
 

Constraints:

1 <= n <= 10^4

## Explanation

### Digit Sum Function: Calculates the sum of the digits of a number.

Group Count: Uses a hash map (unordered_map) to count how many numbers fall into each group, where the key is the sum of digits.
Max Group Size: Keeps track of the largest size of any group.
Count Groups with Max Size: Iterates through the map to count how many groups have the largest size.
You can test this with different values of n to ensure it works as expected!

### Group Numbers by Digit Sum:

Loop through numbers from 1 to n.
Compute the sum of digits for each number.
Update a hash map (groupCount) to track how many numbers belong to each group (keyed by their digit sum).
Find the Largest Group Size:
Track the maximum group size (maxSize) as you populate the map.
Count Groups with Maximum Size:
Iterate through the hash map to count groups that match maxSize.
This solution is efficient and adheres to the problem's constraints.

## Intuition
The problem requires grouping numbers from 1 to n based on their digit sums. The intuition is that numbers with the same digit sum can be grouped together. By iterating through the numbers, calculating their digit sums, and maintaining a record of group sizes, you can find the largest group size and count how many groups achieve it.

## Approach
Group Numbers by Digit Sum:
For each number from 1 to n, calculate the sum of its digits.
Use a hash map (or dictionary) to store the count of numbers that share the same digit sum.
Track Maximum Group Size:
While populating the hash map, keep updating a variable to store the size of the largest group.
Count Groups with Maximum Size:
Iterate through the hash map to count how many groups have the maximum size.

## Complexity
### Time Complexity:

The digit sum calculation for each number takes $$O(\log(\text{n}))$$ time (since the number of digits in n is proportional to $$\log(\text{n})$$). Iterating through all n numbers takes $$O(n)$$. Thus, the overall time complexity is $$O(n \cdot \log(\text{n}))$$.

### Space Complexity:

The hash map may store up to n entries in the worst case, giving a space complexity of $$O(n)$$.