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
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Helper function to perform DFS traversal
    void dfs(TreeNode* root, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount, int& count) {
        if (root == NULL) return;

        // Update the current sum up to this node
        currentSum += root->val;

        // Check if there is a previous sum that makes the current sum equal to targetSum
        if (prefixSumCount.find(currentSum - targetSum) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - targetSum]; // Increment count by the number of times this sum occurred
        }

        // Update the prefix sum count for the current sum
        prefixSumCount[currentSum]++;

        // Continue the DFS traversal
        dfs(root->left, currentSum, targetSum, prefixSumCount, count);
        dfs(root->right, currentSum, targetSum, prefixSumCount, count);

        // After returning from the recursion, decrement the count of the current sum to backtrack
        prefixSumCount[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;  // Map to store the count of prefix sums
        prefixSumCount[0] = 1;  // Initialize with the base case: path sum of 0 is found once
        int count = 0;

        dfs(root, 0, targetSum, prefixSumCount, count);

        return count;
    }
};

