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
    int maxLength = 0;
    int dfs(TreeNode* node, int parentValue) {
        if (!node) return 0;  // Base case: no node, no path
        
        int left = dfs(node->left, node->val);
        int right = dfs(node->right, node->val);

        maxLength = max(maxLength, left + right);  // Update global maxLength
        
        if(node->val==parentValue)
        return max(left,right)+1;
        else
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) 
    {
        if(root==NULL)
        return 0;
        dfs(root,-1);
        return maxLength;
        
    }
};
