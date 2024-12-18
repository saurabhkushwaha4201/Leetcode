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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;  // This will store the final result: a 2D vector for each level of the tree
        if (root == NULL)  // If the tree is empty, return an empty result
            return ans;

        queue<TreeNode*> q;  // Queue to hold nodes at the current level
        q.push(root);  // Push the root node into the queue
        bool leftToRight = true;  // Flag to toggle between left-to-right and right-to-left traversal

        while (!q.empty())  // Continue processing as long as there are nodes in the queue
        {
            int size = q.size();  // The number of nodes at the current level
            vector<int> result;  // To store the values of the nodes at the current level

            // Process each node at the current level
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();  // Get the node at the front of the queue
                q.pop();  // Remove the node from the queue
                result.push_back(temp->val);  // Add the node's value to the result vector

                // If the node has a left child, enqueue it for the next level
                if (temp->left) 
                    q.push(temp->left);

                // If the node has a right child, enqueue it for the next level
                if (temp->right)
                    q.push(temp->right);
            }

            // After processing the current level, check if the traversal direction is left-to-right
            if (leftToRight)
                ans.push_back(result);  // If so, just add the result as it is
            else
            {
                reverse(result.begin(), result.end());  // Otherwise, reverse the result to achieve right-to-left traversal
                ans.push_back(result);  // Add the reversed result to the answer
            }

            // Toggle the direction for the next level
            leftToRight = !leftToRight;
        }

        return ans;  // Return the final zigzag level order traversal
    }
};

