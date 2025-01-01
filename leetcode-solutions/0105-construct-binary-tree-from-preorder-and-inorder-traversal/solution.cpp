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
    // Helper function to build the binary tree
    TreeNode* buildTreeRecursive(vector<int>& preorder, int& preIndex,
                                 unordered_map<int, int>& valueToInorderIndex, 
                                 int inStart, int inEnd) {

        // Base condition: if there are no elements to process, return NULL
        if (inStart > inEnd) {
            return NULL;
        }

        // Get the current root value from preorder traversal
        int rootValue = preorder[preIndex++];

        // Create the root node
        TreeNode* root = new TreeNode(rootValue);

        // Get the index of the root value in the inorder traversal
        int inorderRootIndex = valueToInorderIndex[rootValue];

        // Recursively build the left subtree
        root->left = buildTreeRecursive(preorder, preIndex, valueToInorderIndex, 
                                        inStart, inorderRootIndex - 1);

        // Recursively build the right subtree
        root->right = buildTreeRecursive(preorder, preIndex, valueToInorderIndex, 
                                         inorderRootIndex + 1, inEnd);

        // Return the root of the constructed tree
        return root;
    }

    // Main function to build the binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // Create a mapping from node value to its index in inorder traversal for quick lookup
        unordered_map<int, int> valueToInorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            valueToInorderIndex[inorder[i]] = i;
        }

        // Initialize preIndex to track the current index in preorder traversal
        int preIndex = 0;

        // Start the recursive tree building process
        return buildTreeRecursive(preorder, preIndex, valueToInorderIndex, 0, inorder.size() - 1);
    }
};

