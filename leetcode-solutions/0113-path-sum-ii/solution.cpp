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
    void dfs(TreeNode* root,vector<vector<int>>&ans,vector<int>result,int targetSum)
    {
        if(root==NULL)
        return;
        result.push_back(root->val);
        targetSum -= root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum==0)
            ans.push_back(result);
        }
        else
        {
            dfs(root->left,ans,result,targetSum);
            dfs(root->right,ans,result,targetSum);
        }
       result.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        vector<int>result;
        dfs(root,ans,result,targetSum);
        return ans;
    }
};
