class Solution {
public:
    bool isBST(TreeNode* root, long long minValue, long long maxValue) {
        if (root == NULL)
            return true;
        
        // Ensure that root->val is strictly greater than minValue and strictly less than maxValue
        if (root->val > minValue && root->val < maxValue) {
            bool left = isBST(root->left, minValue, root->val);  // Left child must be less than root->val
            bool right = isBST(root->right, root->val, maxValue);  // Right child must be greater than root->val
            return left && right;
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        return isBST(root, LONG_MIN, LONG_MAX);  // Use long long to handle boundary cases
    }
};

