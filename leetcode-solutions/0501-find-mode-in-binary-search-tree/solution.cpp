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
    int currentVal = INT_MIN;
    int currentCount = 0;
    int maxCount = 0;
    vector<int> mode;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        // Traverse the left subtree
        inorder(root->left);

        if(currentVal==root->val)
        {
            currentCount++;
        }
        else
        {
            currentVal = root->val;
            currentCount = 1;
        }
        if(currentCount>maxCount)
        {
            maxCount = currentCount;
            mode.clear();
            mode.push_back(root->val);
        }
        else if(currentCount==maxCount)
        {
            mode.push_back(root->val);
        }

        // Traverse the right subtree
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return mode;  // Return an empty mode list for an empty tree

        inorder(root);  // Start the in-order traversal

        

        return mode;  // Return the mode list
    }
};

