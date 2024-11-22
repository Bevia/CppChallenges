##  shortest-path algorithms

1. Dijkstra’s Algorithm

	•	Use Case: Finds the shortest path from a single source to all other nodes in a graph with non-negative edge weights.
	•	Time Complexity: O(V^2) with an adjacency matrix, or O(E log V) with a priority queue (using a min-heap).
	•	How it works:
	•	It repeatedly selects the node with the smallest tentative distance, updates the distances of its neighbors, and moves to the next closest node until all nodes are visited.

2. Bellman-Ford Algorithm

	•	Use Case: Finds the shortest paths from a single source to all other nodes in a graph. It works even if the graph has negative weight edges but cannot handle negative weight cycles.
	•	Time Complexity: O(V * E), where ￼ is the number of vertices and ￼ is the number of edges.
	•	How it works:
	•	It repeatedly relaxes all the edges of the graph, updating the tentative distances to nodes.
	•	The algorithm runs for ￼ iterations, where ￼ is the number of vertices. If any distance is updated on the ￼ iteration, it indicates a negative weight cycle.

3. Floyd-Warshall Algorithm

	•	Use Case: Finds the shortest paths between all pairs of nodes in a graph. This is a dynamic programming approach.
	•	Time Complexity: O(V^3), where ￼ is the number of vertices.
	•	How it works:
	•	It iteratively improves the shortest path between all pairs of nodes by considering whether a direct path or an indirect path (through another node) offers a shorter distance.
	•	It is suitable for dense graphs and small to medium-sized graphs, as its time complexity grows quickly with the number of nodes.

4. A (A-star) Algorithm*

	•	Use Case: Finds the shortest path from a single source to a target node. It is particularly useful for pathfinding on maps, where the nodes represent locations on a grid or graph, and you have an estimate of the distance to the target node (called a heuristic).
	•	Time Complexity: O(E) in the best case, but can be up to O(E * log V) with certain implementations, where ￼ is the number of edges and ￼ is the number of vertices.
	•	How it works:
	•	A* combines Dijkstra’s algorithm with a heuristic to estimate the remaining cost to reach the target node.
	•	The heuristic function helps guide the search toward the goal, making A* faster than Dijkstra in practice when a good heuristic is available.

5. Johnson’s Algorithm

	•	Use Case: Finds the shortest paths between all pairs of nodes in a graph, like the Floyd-Warshall algorithm, but more efficient in sparse graphs.
	•	Time Complexity: O(V^2 log V + VE), where ￼ is the number of vertices and ￼ is the number of edges.
	•	How it works:
	•	It reweights the edges using a technique called reduced costs, which removes negative weights from the graph.
	•	Then, it runs Dijkstra’s algorithm from each vertex, similar to running Dijkstra multiple times.

6. Breadth-First Search (BFS)

	•	Use Case: Finds the shortest path in an unweighted graph (or a graph where each edge has the same weight).
	•	Time Complexity: O(V + E), where ￼ is the number of vertices and ￼ is the number of edges.
	•	How it works:
	•	BFS explores nodes level by level, starting from the source node.
	•	The first time a node is reached, it’s guaranteed to be via the shortest path in terms of the number of edges, making BFS an optimal algorithm for unweighted graphs.

7. Bidirectional Search

	•	Use Case: Finds the shortest path between two specific nodes, usually in an unweighted graph.
	•	Time Complexity: O(√E) under optimal conditions (for large graphs), where ￼ is the number of edges.
	•	How it works:
	•	Bidirectional search runs two simultaneous searches: one from the source node and one from the target node, expanding outwards.
	•	When the two searches meet, the path has been found. This approach can significantly reduce the search space in large graphs.

8. Greedy Best-First Search

	•	Use Case: Finds a path from a start node to a target node based on the lowest cost to the target, similar to A* but without considering the cost from the start node.
	•	Time Complexity: Depends on the heuristic, often O(E log V) with priority queues.
	•	How it works:
	•	The algorithm selects the node that appears to be closest to the target based on a heuristic, but it doesn’t account for the actual path cost (only the heuristic). It’s not guaranteed to find the shortest path, unlike A* or Dijkstra.

9. TopoSort + Dynamic Programming (for Directed Acyclic Graphs)

	•	Use Case: Finds the shortest path in Directed Acyclic Graphs (DAGs).
	•	Time Complexity: O(V + E), where ￼ is the number of vertices and ￼ is the number of edges.
	•	How it works:
	•	Topologically sort the DAG, then use dynamic programming to relax the edges in the topological order, ensuring that the shortest path is found.

### Summary of Algorithms:

| Algorithm        | Type            | Use Case                                | Time Complexity                         |
|------------------|-----------------|-----------------------------------------|-----------------------------------------|
| Dijkstra         | Single-source   | Non-negative weighted graphs            | O(V²) / O(E log V)                      |
| Bellman-Ford     | Single-source   | Graphs with negative weights            | O(V * E)                                |
| Floyd-Warshall   | All-pairs       | Dense graphs, small to medium size      | O(V³)                                   |
| A*               | Single-source   | Pathfinding with heuristic              | O(E) (best case)                        |
| Johnson          | All-pairs       | Sparse graphs                           | O(V² log V + VE)                        |
| BFS              | Single-source   | Unweighted graphs                       | O(V + E)                                |
| Bidirectional    | Single-source   | Pathfinding between two nodes           | O(√E)                                   |
| Greedy Best-First| Single-source   | Pathfinding with heuristic              | O(E log V)                              |
| TopoSort + DP    | DAGs            | Shortest path in DAGs                   | O(V + E)                                |

Each algorithm has its own strengths and weaknesses, and the choice of algorithm depends on the nature of the graph (e.g., weighted, unweighted, with negative edges) and the specific problem requirements.

### Note:

Depth-First Search (DFS) is another important graph traversal algorithm, but it is not typically used for finding the shortest path in a graph. Unlike algorithms specifically designed for shortest path problems, DFS explores a graph by going as deep as possible along each branch before backtracking, without considering edge weights or the distance from the source node.

Would DFS fit in the list of shortest-path algorithms?

	•	Not directly: DFS does not guarantee the shortest path, as it may explore paths that are longer before reaching the target node. It’s primarily used for tasks like finding a connected component or checking if a path exists between two nodes, but not for computing the shortest path.

However, DFS can be part of a strategy for finding paths in an unweighted graph if you apply it in a way that explores all paths and then manually compare the path lengths. But this is inefficient and doesn’t perform well compared to other algorithms like BFS, Dijkstra, or A*.

DFS in Context:

DFS is primarily used for:
	•	Traversing or exploring a graph.
	•	Solving problems like cycle detection, topological sorting (in directed acyclic graphs), and pathfinding in specific scenarios (like in mazes or puzzle-solving).

It’s not included in the list of shortest-path algorithms because it lacks the necessary criteria (like edge weights or efficient path calculation) to guarantee the shortest distance between nodes. Instead, algorithms like BFS, Dijkstra, or A* are designed to optimize for finding the shortest path.

Summary:

DFS doesn’t fit directly into the category of shortest-path algorithms but is an essential tool for exploring graphs in a variety of other contexts.