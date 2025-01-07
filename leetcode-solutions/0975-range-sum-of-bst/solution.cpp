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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0; // Base case: If the node is NULL, return 0
        }
        
        int sum = 0;

        // If current node's value is within the range, add it to the sum
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // Traverse the left subtree if the current node's value is greater than low
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }

        // Traverse the right subtree if the current node's value is less than high
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};

