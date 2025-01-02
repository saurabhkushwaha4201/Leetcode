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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        // Initialize a queue to perform level-order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);
        
        // Start by assigning the root value to levelSum
        int levelSum = root->val;

        // Continue traversing the tree while there are nodes to process
        while (!q.empty())
        {
            // Get the number of nodes at the current level
            int size = q.size();

            // Initialize the next level sum as 0
            int nextLevelSum = 0;

            // Loop through all nodes at the current level
            for (int i = 0; i < size; i++)
            {
                // Get the front node of the queue (current node)
                TreeNode* curr = q.front();
                q.pop(); // Remove the current node from the queue

                // Replace the current node's value with the sum of cousins' values
                curr->val = levelSum - curr->val;

                // Calculate the sibling sum for the current node's children
                int siblingSum = 0;
                if (curr->left)
                {
                    siblingSum += curr->left->val; // Add left child value to sibling sum
                }
                if (curr->right)
                {
                    siblingSum += curr->right->val; // Add right child value to sibling sum
                }

                // Process the left child if it exists
                if (curr->left)
                {
                    nextLevelSum += curr->left->val; // Add left child value to next level sum
                    curr->left->val = siblingSum;   // Set left child's value to the sibling sum
                    q.push(curr->left); // Push left child to the queue for next level
                }

                // Process the right child if it exists
                if (curr->right)
                {
                    nextLevelSum += curr->right->val; // Add right child value to next level sum
                    curr->right->val = siblingSum;   // Set right child's value to the sibling sum
                    q.push(curr->right); // Push right child to the queue for next level
                }
            }

            // Update the levelSum to be the sum of the next level
            levelSum = nextLevelSum;
        }

        // Return the root of the modified tree
        return root;
    }
};

