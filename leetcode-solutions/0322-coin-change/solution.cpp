class Solution {
public:
    int solve(vector<int>&coins,int amount,int index,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(amount<0 || index>=coins.size())
        {
            return INT_MAX;
        }
        if(dp[index][amount]!=-1)
        return dp[index][amount];

        int take = solve(coins,amount-coins[index],index,dp);
        if(take!=INT_MAX)
        {
            take +=1;
        }
        int notTake = solve(coins,amount,index+1,dp);

        return dp[index][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result = solve(coins,amount,0,dp);
        if(result==INT_MAX)
        return -1;

        return result;
    }
};
