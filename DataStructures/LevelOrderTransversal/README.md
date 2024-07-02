## Explanation:

### This is a simple example of level order traversal of a binary tree in modern C++ (C++11 and beyond). Level order traversal is also known as breadth-first traversal.

TreeNode Structure: This defines the structure of a node in the binary tree, which contains an integer value and pointers to the left and right children.

levelOrderTraversal Function: This function performs the level order traversal. It uses a queue to keep track of the nodes to be visited. The root node is first pushed into the queue, and then the function enters a loop where it processes each node, prints its value, and enqueues its children if they exist.

main Function: This function creates a simple binary tree, calls the levelOrderTraversal function to print the values in level order, and then frees the allocated memory.

### to make it run:
g++ ./DataStructures/LevelOrderTransversal/levelordertransversal.cpp ./DataStructures/LevelOrderTransversal/levelordertransversal.cpp -o levelordertransversal 
### To enable C++11, use the following command:
g++ -std=c++11 ./DataStructures/LevelOrderTransversal/levelordertransversal.cpp -o ./DataStructures/LevelOrderTransversal/levelordertransversal.cpp -o levelordertransversal 
### To run the program, use this command:
./levelordertransversal