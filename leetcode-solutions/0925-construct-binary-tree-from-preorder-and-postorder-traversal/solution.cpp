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
    // Helper function to recursively build the tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder,
                        unordered_map<int,int>& postorderIndexMap, 
                        int& preIndex, int postStart, int postEnd)
    {
        // Base case: if the postorder start index exceeds the end index, return NULL (no subtree)
        if (postStart > postEnd)
            return NULL;

        // Create the current root node using the current value from preorder
        TreeNode* root = new TreeNode(preorder[preIndex]);
        // Move the preIndex to the next element in preorder for the next recursive step
        preIndex++;

        // If there's only one element left (i.e., leaf node), no further left or right subtree
        if (postStart == postEnd)
            return root;

        // The next element in preorder is the left subtree root, so we find it in the postorder
        int leftRootVal = preorder[preIndex];
        // Using the postorderIndexMap, get the index of the left root in the postorder array
        int leftRootIndex = postorderIndexMap[leftRootVal];

        // Recursively build the left subtree with the updated bounds
        root->left = buildTree(preorder, postorder, postorderIndexMap, preIndex, postStart, leftRootIndex);

        // Recursively build the right subtree with the updated bounds
        // Right subtree starts from the next index after the left subtree
        root->right = buildTree(preorder, postorder, postorderIndexMap, preIndex, leftRootIndex + 1, postEnd - 1);

        // Return the constructed root node
        return root;
    }

    // Main function to construct the tree from preorder and postorder
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        // Step 1: Create a map to store the indices of each element in the postorder array
        unordered_map<int, int> postorderIndexMap;
        for (int i = 0; i < postorder.size(); i++) {
            postorderIndexMap[postorder[i]] = i;
        }

        // Step 2: Set the initial values for preIndex (to track current position in preorder)
        //          and the bounds for postorder (postStart and postEnd for recursion)
        int preIndex = 0;
        int postStart = 0;
        int postEnd = postorder.size() - 1;

        // Step 3: Call the helper function to construct the tree and return the root
        return buildTree(preorder, postorder, postorderIndexMap, preIndex, postStart, postEnd);
    }
};

