class Solution {
public:
    // Function to calculate the height of the leftmost path
    int findLeftHeight(TreeNode* left)
    {
        int height = 0;
        // Traverse down the left child to find the height
        while(left)
        {
            height++;
            left = left->left;  // Move to the left child
        }
        return height;
    }

    // Function to calculate the height of the rightmost path
    int findRightHeight(TreeNode* right)
    {
        int height = 0;
        // Traverse down the right child to find the height
        while(right)
        {
            height++;
            right = right->right;  // Move to the right child (corrected this line)
        }
        return height;
    }

    int countNodes(TreeNode* root) 
    {
        if(root == NULL)  // If the tree is empty, return 0
            return 0;

        // Get the left and right heights
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        // If left and right heights are equal, the tree is complete and full at this level
        if(lh == rh)
            return (pow(2, lh) - 1);  // A full binary tree at this level has 2^height - 1 nodes

        // If the heights differ, recursively count nodes in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

