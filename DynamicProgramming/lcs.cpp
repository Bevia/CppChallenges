//LCS (Longest Common Subsequence) Problem:
//Given two strings X and Y, the goal is to find the length of their longest subsequence that appears in both strings.

#include <iostream>
#include <vector>
#include <string>

// Function to compute the LCS length
std::string longestCommonSubsequence(const std::string& X, const std::string& Y) {
    int m = X.size();
    int n = Y.size();

    // Create a 2D DP table initialized to 0
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Match: add 1 to the diagonal
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); // No match: take max of left or top
            }
        }
    }

    // Reconstruct the LCS from the DP table
    std::string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1]; // Match: add character to LCS
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i; // Move up
        } else {
            --j; // Move left
        }
    }

    // The LCS is built in reverse order, so reverse it
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    std::string X = "AGGTAB";
    std::string Y = "GXTXAYB";

    std::string lcs = longestCommonSubsequence(X, Y);

    std::cout << "LCS of \"" << X << "\" and \"" << Y << "\" is: \"" << lcs << "\"\n";
    return 0;
}