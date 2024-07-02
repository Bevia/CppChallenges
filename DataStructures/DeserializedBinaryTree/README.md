serialized and deserialized a binary tree

Serialization and deserialization of a binary tree in modern C++ can be accomplished using various techniques. 
One common approach is to use a pre-order traversal for serialization and to reconstruct the tree using a queue during deserialization. 
Below is an example implementation using C++14/17 features.
Serialization

Serialization involves converting the binary tree into a string representation. For simplicity, 
let's use a pre-order traversal (root-left-right) and represent null nodes with a special character (e.g., "#").
Deserialization

Deserialization involves reconstructing the binary tree from the string representation.

