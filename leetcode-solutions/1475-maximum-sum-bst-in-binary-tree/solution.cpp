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
 class subtreeDetails
 {
    public:
    int maxNode,minNode,maxSize,maxSum;
    subtreeDetails(int maxNode,int minNode,int maxSum)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
 };
class Solution {
public:
int maxSum = 0;
    subtreeDetails maxSumBSTHelper(TreeNode*root)
    {
        if(root==NULL)
        {
            return subtreeDetails(INT_MIN,INT_MAX,0);
        }

        subtreeDetails leftSubtree = maxSumBSTHelper(root->left);
        subtreeDetails rightSubtree = maxSumBSTHelper(root->right);

        if(root->val > leftSubtree.maxNode && root->val < rightSubtree.minNode)
        {
            int currentMax = max(root->val,rightSubtree.maxNode);
            int currentMin = min(root->val,leftSubtree.minNode);
            int currentSum = (root->val + leftSubtree.maxSum + rightSubtree.maxSum);
            maxSum = max(maxSum,currentSum);
            return subtreeDetails(currentMax,currentMin,currentSum);
        }

        return subtreeDetails(INT_MAX,INT_MIN,0);
    }
    int maxSumBST(TreeNode* root) 
    {
        maxSumBSTHelper(root);
        return maxSum;  
    }
};
