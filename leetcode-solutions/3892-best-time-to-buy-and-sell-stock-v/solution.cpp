class Solution {
public:
    int n;
    long long solve(int index, int k,int state, vector<int>&prices,vector<vector<vector<long long>>>&dp)
    {
        if(index>=prices.size() || k==0)
        return (state==0)?0LL:LLONG_MIN;
        if(dp[index][k][state]!=LLONG_MIN)
        return dp[index][k][state];
        long long profit = LLONG_MIN;
        // state = 0 not holding anything
        if(state==0)
        {
            // buy
            long long nextBuy =  solve(index+1,k,1,prices,dp);
            long long buy = (nextBuy==LLONG_MIN)?LLONG_MIN : (-1LL*prices[index] +nextBuy);

            long long nextShortSell = solve(index+1,k,2,prices,dp);
            long long shortSell = (nextShortSell==LLONG_MIN) ? LLONG_MIN : 1LL*prices[index] + nextShortSell;
            long long skip =solve(index+1,k,0,prices,dp);
            profit = max({buy,shortSell,skip});

        }
        // state = 1 bought now sold
        else if(state==1)
        {
            long long nextSell = solve(index+1,k-1,0,prices,dp);
            long long sell = (nextSell==LLONG_MIN)?LLONG_MIN:1LL*prices[index] + nextSell;
            long long skip = solve(index+1,k,1,prices,dp);
            profit = max(sell,skip);
        }
        // state = 2 short sell now buy back
        else if(state ==2)
        {
            long long nextBuyBack = solve(index+1,k-1,0,prices,dp);
            long long buyBack = (nextBuyBack==LLONG_MIN)?LLONG_MIN : -1LL*prices[index] +  nextBuyBack;
            long long skip = solve(index+1,k,2,prices,dp);
            profit = max(buyBack,skip);
        }
        return dp[index][k][state]= profit;


    }
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(k+1,vector<long long>(3,LLONG_MIN)));
        return solve(0,k,0,prices,dp);
    }
};
