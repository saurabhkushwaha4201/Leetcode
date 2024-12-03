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
    // Helper function to swap values of nodes at odd levels
    void helper(TreeNode* left, TreeNode* right, int level)
    {
        // If any of the nodes is null, return (base case)
        if (left == nullptr || right == nullptr)
            return;

        // Swap the values of nodes at the current level if the level is odd
        if (level % 2 == 1) // Odd level, swap values
        {
            swap(left->val, right->val);
        }

        // Recursively process left and right children of the nodes at the next level
        // Going to the next deeper level (level + 1)
        helper(left->left, right->right, level + 1); // Left child of the left subtree and right child of the right subtree
        helper(left->right, right->left, level + 1); // Right child of the left subtree and left child of the right subtree
    }

    // Main function to reverse the odd levels of the binary tree
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        // Start the recursive function from the left and right children of the root with level 0
        helper(root->left, root->right, 1);
        
        // Return the root after the values at odd levels have been swapped
        return root;
    }
};

