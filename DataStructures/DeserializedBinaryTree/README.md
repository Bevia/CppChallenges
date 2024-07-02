
## Serialized and deserialized a binary tree

Serialization and deserialization of a binary tree in modern C++ can be accomplished using various techniques. 
One common approach is to use a pre-order traversal for serialization and to reconstruct the tree using a queue during deserialization. 
Below is an example implementation using C++14/17 features.
Serialization

Serialization involves converting the binary tree into a string representation. For simplicity, 
let's use a pre-order traversal (root-left-right) and represent null nodes with a special character (e.g., "#").
Deserialization

Deserialization involves reconstructing the binary tree from the string representation.

## Explanation
TreeNode Structure: The TreeNode struct represents a node in the binary tree with a value (val), and pointers to the left and right children.

### Serialize Function:
Uses a lambda function serializeHelper to recursively traverse the tree in pre-order.
If a node is null, it appends "# " to the output stream.
Otherwise, it appends the node's value followed by a space and recursively processes the left and right children.

## Deserialize Function:
Reads the serialized string into a queue of strings, each representing a node.
Uses a lambda function deserializeHelper to reconstruct the tree:
If the queue is empty, it returns nullptr.
It pops the front of the queue and creates a new node if the value is not "#".
Recursively processes the left and right children.

### PrintTree Function:
A helper function to print the tree structure in pre-order to verify correctness.

### to make it run:
g++ ./DataStructures/DeserializedBinaryTree/deserializedbinarytree.cpp ./DataStructures/DeserializedBinaryTree/deserializedbinarytree.cpp -o deserializedbinarytree 
### To enable C++11, use the following command:
g++ -std=c++11 ./DataStructures/DeserializedBinaryTree/deserializedbinarytree.cpp -o ./DataStructures/DeserializedBinaryTree/deserializedbinarytree.cpp -o deserializedbinarytree 
### To run the program, use this command:
./deserializedbinarytree
