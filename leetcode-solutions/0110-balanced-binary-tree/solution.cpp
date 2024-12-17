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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; // Value of the node
 *     TreeNode *left; // Pointer to the left child
 *     TreeNode *right; // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and children
 * };
 */

class Solution {
public:
    // Helper function to calculate height and check balance
    int checkHeight(TreeNode* root) {
        // Base case: If the tree is empty, its height is 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the height of the left subtree
        int leftHeight = checkHeight(root->left);
        
        // If left subtree is unbalanced, propagate the failure (-1)
        if (leftHeight == -1) {
            return -1;
        }

        // Recursively calculate the height of the right subtree
        int rightHeight = checkHeight(root->right);
        
        // If right subtree is unbalanced, propagate the failure (-1)
        if (rightHeight == -1) {
            return -1;
        }

        // Check if the current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Tree is unbalanced
        }

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        // Use the helper function to check balance
        return checkHeight(root) != -1;
    }
};

