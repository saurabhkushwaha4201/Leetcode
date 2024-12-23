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
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> sortedArr(n);

        for (int i = 0; i < n; i++) {
            sortedArr[i] = {arr[i], i};
        }

        sort(sortedArr.begin(), sortedArr.end());

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            while (sortedArr[i].second != i) {
                int correctIndex = sortedArr[i].second;
                swap(sortedArr[i], sortedArr[correctIndex]);
                swaps++;
            }
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int count = 0;
        while(!q.empty())
        {
            vector<int>temp;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            count += minSwaps(temp);
            
        }

        return count;
        
    }
};
