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
    void inorder(TreeNode* node, TreeNode*& current) {
        if (!node) return;
        
        // Recursively visit the left subtree.
        inorder(node->left, current);
        
        // Remove the left child and attach the node to the right of 'current'.
        node->left = nullptr;
        current->right = node;
        current = node;  // Move current to this node.
        
        // Recursively visit the right subtree.
        inorder(node->right, current);
    }
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode* dummy = new TreeNode(0);  // A dummy node to serve as the new root.
        TreeNode* current = dummy;  // Pointer to keep track of the last node in the new tree.

        // Helper function to perform the inorder traversal.
        inorder(root, current);

        return dummy->right;  // Return the new root of the tree (dummy's right child).
    }
    
};
