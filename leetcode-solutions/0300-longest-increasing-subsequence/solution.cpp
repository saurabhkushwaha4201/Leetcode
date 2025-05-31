class Solution {
public:
    // int solve(vector<int>& nums, int index, int prev, vector<vector<int>>& dp)
    // {
    //     if(index < 0)
    //         return 0;

    //     if(dp[index][prev+1] != -1)
    //         return dp[index][prev+1];

    //     int take = 0;
    //     if(prev == -1 || nums[prev] > nums[index])
    //     {
    //         take = 1 + solve(nums, index - 1, index, dp);
    //     }
    //     int notTake = solve(nums, index - 1, prev, dp);

        
    //     return dp[index][prev+1] = max(take, notTake);
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // prev ranges from -1 to n-1, so size is n+1
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(nums, n-1, -1, dp);
        vector<int>dp(n,1);
        int lisLength = 1;
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            lisLength = max(lisLength,dp[i]);
        }
        return lisLength;
    }
};

