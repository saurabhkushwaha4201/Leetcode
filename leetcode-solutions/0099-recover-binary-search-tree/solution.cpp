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
    // Pointers to hold the first and second nodes that are out of order
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    
    // Pointer to track the previous node during inorder traversal
    TreeNode* prev = NULL;

    // Function to perform an inorder traversal and detect swapped nodes
    void inorder(TreeNode* root) {
        // Base case: if the node is null, just return
        if (root == NULL) return;

        // Recursively visit the left child
        inorder(root->left);

        // Check if there is a violation in the inorder sequence
        if (prev != NULL && prev->val > root->val) {
            // This condition checks if the previous node's value is greater than the current node's value.
            // If this happens, it indicates that these nodes are swapped, violating the BST property.

            // If this is the first violation, set 'first' to the previous node
            if (first == NULL) {
                first = prev;
            }
            // Set 'second' to the current node (the second node that is out of order)
            second = root;
        }

        // Move the 'prev' pointer to the current node for the next comparison
        prev = root;

        // Recursively visit the right child
        inorder(root->right);
    }

    // Function to recover the BST by swapping the values of the two misplaced nodes
    void recoverTree(TreeNode* root) {
        // Step 1: Perform inorder traversal to detect the swapped nodes
        inorder(root);

        // Step 2: If we have found both the misplaced nodes, swap their values
        if (first && second) {
            swap(first->val, second->val);  // Swap values to correct the tree
        }
    }
};

