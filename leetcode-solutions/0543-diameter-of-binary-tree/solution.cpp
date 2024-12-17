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
    // Global variable to store the maximum diameter
    int maxDiameter = 0;

    // Helper function to calculate height and update diameter
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Height of an empty tree is 0
        }

        // Recursively calculate heights of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Update the diameter
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to calculate the diameter
    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // Perform a single traversal to calculate diameter
        return maxDiameter; // Return the maximum diameter
    }
};

