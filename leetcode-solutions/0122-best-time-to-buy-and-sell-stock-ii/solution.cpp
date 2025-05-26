class Solution {
public:
    int solve(vector<int>&prices, int index, int buy, vector<vector<int>>&dp)
    {
        if(index==prices.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        return dp[index][buy];
        int profit = 0;
        if(buy==1) // buy = 1 means we have to buy
        {
            int buy = (-prices[index]) + solve(prices,index+1,0, dp);
            int notBuy = solve(prices, index+1, 1, dp);
            profit = max(buy, notBuy);
        }
        else    // buy = 0 means we have to sell
        {
            int sell = prices[index] + solve(prices, index+1, 1, dp);
            int notSell = solve(prices, index+1, 0, dp);
            profit = max(sell, notSell);
        }
        return dp[index][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices, 0, 1, dp);


    }
};
