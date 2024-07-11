#include <iostream>
#include <vector>
#include <algorithm> // For std::min

// Function to find the minimum cost path in a grid
int minCostPath(const std::vector<std::vector<int>>& cost) {
    int rows = cost.size();
    int cols = cost[0].size();
    
    // Create a 2D dp vector to store the minimum cost to reach each cell
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
    
    // Initialize the dp array
    dp[0][0] = cost[0][0];
    
    // Initialize the first column of the dp array
    for (int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
    
    // Initialize the first row of the dp array
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }
    
    // Fill the rest of the dp array
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
        }
    }
    
    // The minimum cost path will be stored in the bottom-right corner of the dp array
    return dp[rows-1][cols-1];
}

int main() {
    // Example grid with costs
    std::vector<std::vector<int>> cost = {
        {1, 3, 5, 8},
        {4, 2, 1, 7},
        {4, 3, 2, 3}
    };
    
    std::cout << "Minimum cost to reach bottom-right corner: " << minCostPath(cost) << std::endl;
    
    return 0;
}
