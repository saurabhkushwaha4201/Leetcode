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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) 
    {
        // if val is greater than root then val  will be root
        if(val>root->val)
        {
            TreeNode * newNode  = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        // if val is smaller than root then insert in right subTree
        if(root->right)
        {
            root->right = insertIntoMaxTree(root->right,val);
        }
        // if ther is no right child
        else
        {
            root->right = new TreeNode(val);
        }
        return root;
    }
};
