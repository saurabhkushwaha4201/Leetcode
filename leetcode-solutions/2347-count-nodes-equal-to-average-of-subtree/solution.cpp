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
    // Helper function to perform DFS and calculate subtree sums and counts
    pair<int, int> dfs(TreeNode* root, int& count) {
        if (root == NULL)
            return {0, 0}; // Return {sum, size} as {0, 0} for null nodes

        // Recursively calculate left and right subtree sums and sizes
        auto left = dfs(root->left, count);
        auto right = dfs(root->right, count);

        // Calculate the sum and size of the current subtree
        int subTreeSum = left.first + right.first + root->val;
        int subTreeSize = left.second + right.second + 1; // Include current node

        // Check if the average of the subtree matches the current node's value
        if (subTreeSum / subTreeSize == root->val) {
            count++;
        }

        // Return the sum and size of the current subtree
        return {subTreeSum, subTreeSize};
    }

    int averageOfSubtree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int count = 0;
        dfs(root, count); // Perform DFS to calculate the count
        return count; // Return the total count of nodes matching the condition
    }
};

