/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Function to find the middle node
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast two steps and slow one step
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Slow will be at the middle node
        return slow;
    }

    // Function to build the BST from the linked list
    TreeNode* buildTree(ListNode* head) {
        if (head == nullptr) {
            return nullptr; // Base case: no node to process
        }
        
        // Find the middle node (this will be the root of the current subtree)
        ListNode* mid = findMid(head);
        TreeNode* root = new TreeNode(mid->val);  // Create the node with middle value
        
        // Base case: If there's only one node in the list, it's the root node with no left or right child
        if (head == mid) {
            return root;
        }
        
        // Recursively build the left and right subtrees
        // To build the left subtree, we need the list from `head` to just before the middle
        ListNode* leftList = head;
        ListNode* rightList = mid->next;  // The right list starts after the middle
        
        // Disconnect the left part (before the middle) from the list
        ListNode* temp = head;
        while (temp != nullptr && temp->next != mid) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            temp->next = nullptr;  // Break the link between the left and middle parts
        }

        // Recursive calls to build the left and right subtrees
        root->left = buildTree(leftList);  // Build left subtree with the left sublist
        root->right = buildTree(rightList);  // Build right subtree with the right sublist
        
        return root;
    }

    // Main function to convert sorted linked list to BST
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head);
    }
};

