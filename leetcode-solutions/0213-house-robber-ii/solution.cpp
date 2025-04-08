class Solution {
public:
    int solve(vector<int>&nums,int index,vector<int>&dp,int last)
    {
        if(index>=last)
        {
            return 0;
        }
        if(dp[index]!=-1)
        return dp[index];
        int take = nums[index] + solve(nums,index+2,dp,last);
        int skip = solve(nums,index+1,dp,last);
        return dp[index] =  max(take,skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(solve(nums,0,dp1,n-1),solve(nums,1,dp2,n));
    }
};
