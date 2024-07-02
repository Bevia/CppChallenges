#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <memory>

// Define the TreeNode structure
struct TreeNode {
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to serialize the binary tree
std::string serialize(const std::shared_ptr<TreeNode>& root) {
    std::ostringstream out;
    std::function<void(const std::shared_ptr<TreeNode>&)> serializeHelper = [&](const std::shared_ptr<TreeNode>& node) {
        if (!node) {
            out << "# ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left);
        serializeHelper(node->right);
    };
    serializeHelper(root);
    return out.str();
}

// Function to deserialize the binary tree
std::shared_ptr<TreeNode> deserialize(const std::string& data) {
    std::istringstream in(data);
    std::queue<std::string> nodes;
    std::string node;
    while (in >> node) {
        nodes.push(node);
    }
    std::function<std::shared_ptr<TreeNode>()> deserializeHelper = [&]() {
        if (nodes.empty()) return std::shared_ptr<TreeNode>(nullptr);
        std::string val = nodes.front();
        nodes.pop();
        if (val == "#") return std::shared_ptr<TreeNode>(nullptr);
        auto root = std::make_shared<TreeNode>(std::stoi(val));
        root->left = deserializeHelper();
        root->right = deserializeHelper();
        return root;
    };
    return deserializeHelper();
}

// Helper function to print the tree (for testing purposes)
void printTree(const std::shared_ptr<TreeNode>& root) {
    if (!root) {
        std::cout << "# ";
        return;
    }
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Create a simple binary tree for testing
    auto root = std::make_shared<TreeNode>(1);
    root->left = std::make_shared<TreeNode>(2);
    root->right = std::make_shared<TreeNode>(3);
    root->right->left = std::make_shared<TreeNode>(4);
    root->right->right = std::make_shared<TreeNode>(5);

    // Serialize the tree
    std::string serializedTree = serialize(root);
    std::cout << "Serialized Tree: " << serializedTree << std::endl;

    // Deserialize the tree
    auto deserializedTree = deserialize(serializedTree);

    // Print the deserialized tree to verify correctness
    std::cout << "Deserialized Tree: ";
    printTree(deserializedTree);
    std::cout << std::endl;

    return 0;
}
