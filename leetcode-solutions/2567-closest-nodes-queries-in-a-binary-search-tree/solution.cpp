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
    void inorder(TreeNode* root, vector<int>& sortedValues) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, sortedValues);
        sortedValues.push_back(root->val);
        inorder(root->right, sortedValues);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        vector<int>sortedValues;
        inorder(root,sortedValues);
        vector<vector<int>>result;
        vector<int>answer;
        for(auto x : queries)
        {
            auto max = lower_bound(sortedValues.begin(),sortedValues.end(),x);
            int maxi = -1;
            int mini = -1;
            if(max !=sortedValues.end() && *max==x)
            {
                mini = *max;
            }
            else if(max != sortedValues.begin())
            {
                mini = *prev(max);
            }

            if(max==sortedValues.end())
            {
                maxi = -1;
            }
            else
            {
                maxi = *max;
            }
            
            result.push_back({mini,maxi});
        }
        return result;
    }
};
