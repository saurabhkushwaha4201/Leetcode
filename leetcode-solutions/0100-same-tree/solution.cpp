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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Create two queues for level-order traversal
        queue<TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);

        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* node1 = queue1.front();
            TreeNode* node2 = queue2.front();
            queue1.pop();
            queue2.pop();

            // If both nodes are null, continue to the next pair
            if (node1 == nullptr && node2 == nullptr) continue;

            // If one is null or the values are different, trees are not identical
            if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) {
                return false;
            }

            // Add children of both nodes to their respective queues
            queue1.push(node1->left);
            queue1.push(node1->right);
            queue2.push(node2->left);
            queue2.push(node2->right);
        }

        // If both queues are empty, the trees are identical
        return queue1.empty() && queue2.empty();
    }
};
