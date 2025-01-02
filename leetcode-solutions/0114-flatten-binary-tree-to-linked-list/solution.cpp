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
    void flatten(TreeNode* root) 
    {
        // Start the process only if root is not NULL
        while(root != NULL)
        {
            // If the current node has no left child, move to the right child
            if(root->left == NULL)
            {
                root = root->right;  // Move to the right child
            }
            else
            {
                // Find the rightmost node in the left subtree
                TreeNode* curr = root->left;

                // Traverse to the rightmost node of the left subtree
                while(curr->right != NULL)
                {
                    curr = curr->right;
                }
                
                // Link the right subtree of the root to the rightmost node
                curr->right = root->right;
                
                // Move the left subtree to the right of the root
                root->right = root->left;
                
                // Set the left child of the root to NULL (since the left child is moved to the right)
                root->left = NULL;

                // Move to the next node in the flattened tree (now the right child)
                root = root->right;
            }
        }
    }
};

