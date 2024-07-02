
## Serialized and deserialized a binary tree

Serialization and deserialization of a binary tree in modern C++ can be accomplished using various techniques. 
One common approach is to use a pre-order traversal for serialization and to reconstruct the tree using a queue during deserialization. 
Below is an example implementation using C++14/17 features.
Serialization

Serialization involves converting the binary tree into a string representation. For simplicity, 
let's use a pre-order traversal (root-left-right) and represent null nodes with a special character (e.g., "#").
Deserialization

Deserialization involves reconstructing the binary tree from the string representation.

      1
     / \
    2   3
       / \
      4   5

Pre-order Traversal

In pre-order traversal, we visit nodes in the order: root, left subtree, right subtree.
Step-by-Step Serialization

    Visit Root (1)
        Append 1 to the result.
        Serialized string so far: 1

    Visit Left Subtree of Root (1)
        Root of left subtree is 2.
        Append 2 to the result.
        Serialized string so far: 1 2

    Visit Left Subtree of Node (2)
        Left child of 2 is null.
        Append # to represent null.
        Serialized string so far: 1 2 #

    Visit Right Subtree of Node (2)
        Right child of 2 is null.
        Append # to represent null.
        Serialized string so far: 1 2 # #

    Visit Right Subtree of Root (1)
        Root of right subtree is 3.
        Append 3 to the result.
        Serialized string so far: 1 2 # # 3

    Visit Left Subtree of Node (3)
        Root of left subtree is 4.
        Append 4 to the result.
        Serialized string so far: 1 2 # # 3 4

    Visit Left Subtree of Node (4)
        Left child of 4 is null.
        Append # to represent null.
        Serialized string so far: 1 2 # # 3 4 #

    Visit Right Subtree of Node (4)
        Right child of 4 is null.
        Append # to represent null.
        Serialized string so far: 1 2 # # 3 4 # #

    Visit Right Subtree of Node (3)
        Root of right subtree is 5.
        Append 5 to the result.
        Serialized string so far: 1 2 # # 3 4 # # 5

    Visit Left Subtree of Node (5)
        Left child of 5 is null.
        Append # to represent null.
        Serialized string so far: 1 2 # # 3 4 # # 5 #

    Visit Right Subtree of Node (5)
        Right child of 5 is null.
        Append # to represent null.
        Serialized string so far: 1 2 # # 3 4 # # 5 # #

Serialized Tree: 1 2 # # 3 4 # # 5 # # 
Deserialized Tree: 1 2 # # 3 4 # # 5 # # 

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
