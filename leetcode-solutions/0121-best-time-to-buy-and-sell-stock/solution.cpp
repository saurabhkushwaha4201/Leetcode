class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxiProfit = 0;
        int minBuy = prices[0];
        for(int i =1;i<n;i++)
        {
            maxiProfit = max(maxiProfit,(prices[i]-minBuy));
            if(prices[i]<minBuy)
            minBuy = prices[i];
        }
        return maxiProfit;
    }
};
