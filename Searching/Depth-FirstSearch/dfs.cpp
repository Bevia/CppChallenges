#include <iostream>
#include <vector>
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

    // Perform DFS starting from the given source vertex
    void DFS(int start) {
        std::unordered_set<int> visited;
        dfsHelper(start, visited);
    }

private:
    std::vector<std::vector<int>> adjList;

    // Recursive helper function for DFS
    void dfsHelper(int vertex, std::unordered_set<int>& visited) {
        // Mark the current node as visited and print it
        visited.insert(vertex);
        std::cout << "Visited " << vertex << std::endl;

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    std::cout << "Depth-First Search starting from vertex 0:" << std::endl;
    g.DFS(0);

    return 0;
}