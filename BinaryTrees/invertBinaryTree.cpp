// Given the root of a binary tree, invert the tree, and return its root.
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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
