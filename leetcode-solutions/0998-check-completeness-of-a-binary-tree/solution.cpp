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
    int countNode(TreeNode*root)
    {
        if(root==NULL)
        return 0;
        return 1 + (countNode(root->left)) + countNode(root->right);
    }
    bool completeTree(TreeNode*root, int parent,int totalNode)
    {
        if(root==NULL)
        return true;
        if(parent>=totalNode)
        return false;
        // index of left subTree 2*parent +1
        bool leftComplete=completeTree(root->left,2*parent +1,totalNode);
        // index of right subTree 2*parent +2
        bool rightComplete = completeTree(root->right,2*parent+2,totalNode);
        return leftComplete && rightComplete;
    }
    bool isCompleteTree(TreeNode* root) 
    {
        int totalNodes = countNode(root);
        return completeTree(root,0,totalNodes);
        
    }
};
