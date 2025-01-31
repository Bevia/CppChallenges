#include <iostream>
#include <vector>
#include <queue>

// Function to perform Breadth-First Search
void bfs(int start, const std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false); // Track visited nodes
    std::queue<int> q;                              // Queue for BFS

    // Start BFS from the given start node
    visited[start] = true;
    q.push(start);

    std::cout << "BFS Traversal: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        std::cout << current << " ";

        // Visit all adjacent nodes
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    // Create a graph using an adjacency list
    // Example graph:
    // 0 -> 1, 2
    // 1 -> 0, 3, 4
    // 2 -> 0, 5, 6
    // 3 -> 1
    // 4 -> 1
    // 5 -> 2
    // 6 -> 2
    std::vector<std::vector<int>> graph = {
        {1, 2},       // Neighbors of node 0
        {0, 3, 4},    // Neighbors of node 1
        {0, 5, 6},    // Neighbors of node 2
        {1},          // Neighbors of node 3
        {1},          // Neighbors of node 4
        {2},          // Neighbors of node 5
        {2}           // Neighbors of node 6
    };

    // Perform BFS starting from node 0
    bfs(0, graph);

    return 0;
}