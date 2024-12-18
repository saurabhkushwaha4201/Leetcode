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
    int maxSum = INT_MIN;  // This will store the maximum path sum found.

    // Function to calculate the maximum path sum for a given node (root) and its children.
    int maxPath(TreeNode* root)
    {
        if(root == NULL)  // Base case: If the node is null, the path sum is 0.
            return 0;

        // Recursively calculate the maximum path sum of the left and right subtrees.
        int leftSum = max(0, maxPath(root->left));  // Only take positive sums, as negative paths don't help in maximizing the total sum.
        int rightSum = max(0, maxPath(root->right));

        // Update the overall maximum sum considering the current node and its left and right children.
        maxSum = max(maxSum, root->val + leftSum + rightSum);

        // Return the maximum path sum that includes the current node and one of its children.
        return root->val + max(leftSum, rightSum);
    }

    // Function to return the maximum path sum for the entire tree.
    int maxPathSum(TreeNode* root) 
    {
        maxPath(root);  // Start calculating the path sums from the root.
        return maxSum;  // Return the global maximum path sum found.
    }
};

