## How to run:
    g++ ./Searching/Depth-FirstSearch/dfs.cpp ./Searching/Depth-FirstSearch/dfs.cpp -o dfs 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Searching/Depth-FirstSearch/dfs.cpp -o ./Searching/Depth-FirstSearch/dfs.cpp -o dfs 
#### To run the program, use this command:
    ./dfs

### run the python file to generarte the plot
python3 ./Searching/Breadth-FirstSearch/bfc_plot.py

Explanation:

	1.	Graph Representation: The graph is represented as an adjacency list, just like in the BFS implementation.
	2.	DFS Method: The DFS function serves as the entry point, and it calls a recursive helper function (dfsHelper) that explores each vertex.
	3.	Recursive Approach: The dfsHelper function recursively explores each node’s neighbors, marking them as visited and printing them when first encountered.
	4.	Edge Addition: The addEdge method adds undirected edges between two vertices.