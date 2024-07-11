#include <iostream>
#include <vector>
#include <fstream>

int minCostPath(const std::vector<std::vector<int>>& cost, std::vector<std::vector<int>>& dp) {
    int rows = cost.size();
    int cols = cost[0].size();
    
    dp.resize(rows, std::vector<int>(cols, 0));
    
    dp[0][0] = cost[0][0];
    
    for (int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
    
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }
    
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
        }
    }
    
    return dp[rows-1][cols-1];
}

void writeDPTableToFile(const std::vector<std::vector<int>>& dp, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& row : dp) {
        for (const auto& cell : row) {
            file << cell << " ";
        }
        file << "\n";
    }
    file.close();
}

int main() {
    std::vector<std::vector<int>> cost = {
        {1, 3, 5, 8},
        {4, 2, 1, 7},
        {4, 3, 2, 3}
    };
    
    std::vector<std::vector<int>> dp;
    int minCost = minCostPath(cost, dp);
    
    std::cout << "Minimum cost to reach bottom-right corner: " << minCost << std::endl;
    
    writeDPTableToFile(dp, "dp_table.txt");
    
    return 0;
}
