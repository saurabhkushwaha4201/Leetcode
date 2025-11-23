class Solution {
public:
    int maxSum;
    int solve(vector<int>&nums,int i,int currRem,vector<vector<int>>&dp){
        if(i>=nums.size()){
            if(currRem==0){
                return 0;
            }else{
                return INT_MIN;
            }
        }
        if(dp[i][currRem]!=-1){
            return dp[i][currRem];
        }
        int take = nums[i] + solve(nums,i+1,(currRem+nums[i])%3,dp);
        int notTake = solve(nums,i+1,currRem,dp);
        return dp[i][currRem] = max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        maxSum = INT_MIN;
        int n = nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return solve(nums,0,0,dp);
    }
};
