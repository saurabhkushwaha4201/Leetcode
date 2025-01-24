/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
        return nullptr;  // Base case: If the tree is empty, return null.
    }

    // If the current node's value is less than low, we discard the left subtree.
    if (root->val < low) {
        return trimBST(root->right, low, high);  // Recursively trim the right subtree.
    }
    
    // If the current node's value is greater than high, we discard the right subtree.
    if (root->val > high) {
        return trimBST(root->left, low, high);  // Recursively trim the left subtree.
    }

    // If the node's value is within the range [low, high], we keep it.
    // Now, we recursively trim both the left and right subtrees.
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;  // Return the current node after trimming its subtrees.
}

};

