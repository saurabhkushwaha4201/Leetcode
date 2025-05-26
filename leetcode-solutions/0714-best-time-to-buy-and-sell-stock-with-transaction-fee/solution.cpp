class Solution {
public:
    // int solve(int index, int canBuy, int fee, vector<int>&prices, vector<vector<int>>&dp)
    // {
    //     if(index>=prices.size())
    //     return 0;

    //     if(dp[index][canBuy]!= -1)
    //     return dp[index][canBuy];

    //     int profit = 0;
    //     if(canBuy)
    //     {
    //         int buy = (-prices[index]) + solve(index+1,0,fee,prices,dp);
    //         int notBuy = solve(index+1,1,fee,prices,dp);
    //         profit = max(buy, notBuy);
    //     }
    //     else
    //     {
    //         int sell = prices[index] - fee + solve(index+1,1,fee,prices,dp);
    //         int notSell = solve(index+1,0,fee,prices,dp);
    //         profit = max(sell, notSell);
    //     }
    //     return dp[index][canBuy] = profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(0,1,fee,prices,dp);

        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int index = n-1;index>=0;index--)
        {
            for(int canBuy = 0;canBuy<=1;canBuy++)
            {
                int profit = 0;
                if(canBuy)
                {
                    int buy = (-prices[index]) + dp[index+1][0];
                    int notBuy = dp[index+1][1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] - fee + dp[index+1][1];
                    int notSell = dp[index+1][0]; 
                    profit = max(sell, notSell);
                }
                dp[index][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};
