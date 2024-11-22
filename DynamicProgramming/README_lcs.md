## LCS

LCS stands for Longest Common Subsequence.

It refers to the problem of finding the longest sequence that appears in the same relative order in two given strings, but not necessarily consecutively.

For example:
	•	Given X = "AGGTAB" and Y = "GXTXAYB", the LCS is "GTAB".
	•	The characters G, T, A, B appear in both strings in the same relative order, even though they are not contiguous.

This problem has applications in:
	•	Bioinformatics (e.g., comparing DNA or protein sequences).
	•	Text comparison (e.g., finding differences between file versions).
	•	Data compression and error correction algorithms.

    Certainly! The Longest Common Subsequence (LCS) problem is a classic example of dynamic programming. Below is an example implementation in modern C++ using a 2D vector for the DP table.

### LCS Problem:

Given two strings X and Y, the goal is to find the length of their longest subsequence that appears in both strings.

#### Explanation:

	1.	DP Table Initialization:
	•	A 2D vector dp[m + 1][n + 1] is used, where m and n are the lengths of the two strings.
	•	dp[i][j] stores the length of the LCS of the first i characters of X and the first j characters of Y.
	2.	Filling the Table:
	•	If characters match (X[i-1] == Y[j-1]), the LCS length increases by 1:

dp[i][j] = dp[i - 1][j - 1] + 1;


	•	Otherwise, the value is the maximum of excluding one character from either string:

dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);


	3.	Reconstructing the LCS:
	•	Start from dp[m][n] and backtrack to find the LCS characters.
	•	If X[i-1] == Y[j-1], it’s part of the LCS.
	•	Otherwise, move in the direction of the larger value (dp[i-1][j] or dp[i][j-1]).
	4.	Output:
The LCS is built in reverse order, so it’s reversed at the end.

Example Run:

For X = "AGGTAB" and Y = "GXTXAYB", the DP table would look like this:

  0 G X T X A Y B
0 0 0 0 0 0 0 0 0
A 0 0 0 0 0 1 1 1
G 0 1 1 1 1 1 1 1
G 0 1 1 1 1 1 1 1
T 0 1 1 2 2 2 2 2
A 0 1 1 2 2 3 3 3
B 0 1 1 2 2 3 3 4

Output:

LCS of "AGGTAB" and "GXTXAYB" is: "GTAB"

Features of Modern C++ Used:

	•	std::vector: Used for dynamic 2D table allocation.
	•	std::string: Easy string manipulation and reconstruction of the LCS.
	•	std::reverse: To reverse the reconstructed LCS.
	•	Range-based for loops and clean syntax for improved readability.