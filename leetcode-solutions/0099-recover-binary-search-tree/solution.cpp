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
    vector<int>inorder;
    int index = 0;
    void inorderTraversal(TreeNode* root)
    {
        if(root==NULL)
        return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    void recover(TreeNode* root)
    {
        if(root==NULL)
        return;

        recover(root->left);

        if(root->val!=inorder[index])
        root->val = inorder[index];

        index++;

        recover(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        if(root==NULL)
        return;

        inorderTraversal(root);
        sort(inorder.begin(),inorder.end());
        recover(root);
    }
};
