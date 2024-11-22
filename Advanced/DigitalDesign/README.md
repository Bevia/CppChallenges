## Kernighan’s Algorithm

Kernighan’s Algorithm refers to Kernighan-Lin Algorithm, a heuristic for solving the graph partitioning problem. It is widely used in applications like VLSI design, network partitioning, and clustering. The algorithm was developed by Brian W. Kernighan and Shen Lin in 1970.

Problem Statement

The goal of the algorithm is to partition the nodes of a graph into two subsets such that the cut size (the total weight of the edges connecting nodes in different subsets) is minimized. For unweighted graphs, this simply refers to minimizing the number of edges between the two subsets.

Key Concepts

	1.	Initial Partition: Start with an arbitrary partition of the graph into two subsets of equal (or approximately equal) size.
	2.	Gain Calculation: For each node, calculate the “gain” associated with swapping it to the opposite subset. The gain measures the reduction (or increase) in the cut size.
	3.	Swap Nodes: Iteratively swap pairs of nodes between the subsets to maximize the reduction in the cut size.
	4.	Lock Nodes: Once a pair of nodes has been swapped, they are “locked” and cannot be swapped again in the current iteration.
	5.	Repeat: Perform multiple passes until no further improvement can be made to the cut size.

Algorithm Steps

	1.	Initialization:
	•	Divide the graph nodes into two subsets ￼ and ￼, usually of equal size.
	2.	Compute Initial Gains:
	•	For each node, calculate the gain as:
￼
where ￼ is the difference between the sum of edge weights to the opposite subset and the current subset for node ￼, and ￼ is the weight of the edge connecting ￼ and ￼.
	3.	Find Node Pair to Swap:
	•	Identify the pair of nodes (one from each subset) that provides the maximum reduction in the cut size.
	4.	Swap and Lock:
	•	Swap the selected nodes and “lock” them, meaning they cannot be swapped again in the current iteration.
	5.	Update Gains:
	•	Recompute the gains for the remaining unlocked nodes.
	6.	Iterate:
	•	Repeat the process of selecting and swapping nodes until all nodes are locked.
	7.	Update Partition:
	•	If the cut size has improved, adopt the new partition; otherwise, terminate.

Complexity

	•	The algorithm has a time complexity of ￼ per iteration, where ￼ is the number of nodes.
	•	It is not guaranteed to find the globally optimal solution but often produces good results.

Applications

	•	Circuit design and VLSI layout optimization.
	•	Social network analysis and clustering.
	•	Load balancing in parallel computing.
