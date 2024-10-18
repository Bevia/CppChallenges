#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <memory>

/*
Lets apply Composite Design Pattern to serialize and deserialize a binary tree.

To apply the Composite Design Pattern to this code, we need to recognize that t
his pattern is used to represent part-whole hierarchies. 
It allows treating individual objects and composites (collections of objects) uniformly. 
In this case, the TreeNode class represents a component in a binary tree structure, 
which is a classic example of where the Composite Pattern could be applied.
*/

// Component Interface
class Component {
public:
    virtual ~Component() = default;
    virtual std::string serialize() const = 0;
    virtual void print() const = 0;
};

// Leaf and Composite class (TreeNode)
class TreeNode : public Component {
public:
    int val;
    std::shared_ptr<Component> left;
    std::shared_ptr<Component> right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Serialize the tree starting from this node
    std::string serialize() const override {
        std::ostringstream out;
        std::function<void(const std::shared_ptr<Component>&)> serializeHelper = [&](const std::shared_ptr<Component>& node) {
            if (!node) {
                out << "# ";
                return;
            }
            // Downcast to TreeNode to access val
            auto treeNode = std::dynamic_pointer_cast<TreeNode>(node);
            out << treeNode->val << " ";
            serializeHelper(treeNode->left);
            serializeHelper(treeNode->right);
        };
        serializeHelper(std::make_shared<TreeNode>(*this));
        return out.str();
    }

    // Print the tree starting from this node
    void print() const override {
        if (!this) {
            std::cout << "# ";
            return;
        }
        std::cout << val << " ";
        if (left) left->print();
        else std::cout << "# ";
        if (right) right->print();
        else std::cout << "# ";
    }
};

// Function to deserialize the binary tree from a serialized string
std::shared_ptr<Component> deserialize(const std::string& data) {
    std::istringstream in(data);
    std::queue<std::string> nodes;
    std::string node;
    while (in >> node) {
        nodes.push(node);
    }
    std::function<std::shared_ptr<Component>()> deserializeHelper = [&]() {
        if (nodes.empty()) return std::shared_ptr<Component>(nullptr);
        std::string val = nodes.front();
        nodes.pop();
        if (val == "#") return std::shared_ptr<Component>(nullptr);
        auto root = std::make_shared<TreeNode>(std::stoi(val));
        root->left = deserializeHelper();
        root->right = deserializeHelper();
        return root;
    };
    return deserializeHelper();
}

int main() {
    // Create a simple binary tree for testing
    auto root = std::make_shared<TreeNode>(1);
    root->left = std::make_shared<TreeNode>(2);
    root->right = std::make_shared<TreeNode>(3);
    std::dynamic_pointer_cast<TreeNode>(root->right)->left = std::make_shared<TreeNode>(4);
    std::dynamic_pointer_cast<TreeNode>(root->right)->right = std::make_shared<TreeNode>(5);

    // Serialize the tree
    std::string serializedTree = root->serialize();
    std::cout << "Serialized Tree: " << serializedTree << std::endl;

    // Deserialize the tree
    auto deserializedTree = deserialize(serializedTree);

    // Print the deserialized tree to verify correctness
    std::cout << "Deserialized Tree: ";
    deserializedTree->print();
    std::cout << std::endl;

    return 0;
}