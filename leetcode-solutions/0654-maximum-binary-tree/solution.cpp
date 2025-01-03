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
    TreeNode* treeBuild(vector<int>&nums,int start,int end,map<int,int>&mpp)
    {
        if(start>end || start>nums.size()||end<0)
        return NULL;
        int maxi = INT_MIN;
        for(int i =start;i<=end;i++)
        {
            maxi = max(maxi,nums[i]);
        }
        TreeNode* root = new TreeNode(maxi);

        int rootIndex = mpp[maxi];
        root->left  = treeBuild(nums,start,rootIndex-1,mpp);
        root->right = treeBuild(nums,rootIndex+1,end,mpp);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]=i;
        }
        int start = 0;
        int end  = nums.size()-1;
        return treeBuild(nums,start,end,mpp);
    }
};
