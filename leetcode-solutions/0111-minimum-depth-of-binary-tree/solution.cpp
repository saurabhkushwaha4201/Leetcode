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
    int minDepth(TreeNode* root) 
    {
        // If the root is NULL, the tree is empty, return depth 0
        if (root == NULL) {
            return 0;
        }

        // If there is no left child, we need to calculate the depth from the right child
        if (root->left == NULL) {
            return 1 + minDepth(root->right); // Only go down the right subtree
        }
        
        // If there is no right child, we need to calculate the depth from the left child
        if (root->right == NULL) {
            return 1 + minDepth(root->left); // Only go down the left subtree
        }

        // If both left and right children exist, find the minimum depth of both subtrees
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        // Return the minimum of the two depths plus 1 for the current node
        return 1 + min(leftDepth, rightDepth);
    }
};

