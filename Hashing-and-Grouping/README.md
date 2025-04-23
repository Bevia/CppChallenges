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