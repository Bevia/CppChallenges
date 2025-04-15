#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inverts the binary tree.
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    // Recursively invert the left and right subtrees
    TreeNode* leftSubtree = invertTree(root->left);
    TreeNode* rightSubtree = invertTree(root->right);
    // Swap the left and right pointers
    root->left = rightSubtree;
    root->right = leftSubtree;
    return root;
}

// Helper function to print the tree in-order.
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Construct the binary tree [4,2,7,1,3,6,9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree (in-order traversal): ";
    printTree(root);
    cout << endl;

    // Invert the binary tree
    root = invertTree(root);

    cout << "Inverted tree (in-order traversal): ";
    printTree(root);
    cout << endl;

    return 0;
}
