#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Graph {
public:
    Graph(int vertices) {
        adjList.resize(vertices);
    }

    // Add an undirected edge between two vertices
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's an undirected graph
    }

    // Perform BFS starting from the given source vertex
    void BFS(int start) {
        std::queue<int> q;
        std::unordered_set<int> visited;

        // Start from the given vertex
        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            std::cout << "Visited " << current << std::endl;

            // Visit all the adjacent vertices
            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }

private:
    std::vector<std::vector<int>> adjList;
};

int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    std::cout << "Breadth-First Search starting from vertex 0:" << std::endl;
    g.BFS(0);

    return 0;
}