class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> pricePrefix(n + 1, 0);
        vector<long long> basePrefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pricePrefix[i + 1] = pricePrefix[i] + prices[i];
            basePrefix[i + 1] = basePrefix[i] + 1LL * prices[i] * strategy[i];
        }

        long long initialProfit = basePrefix[n];
        long long ans = initialProfit;

        for (int i = k; i <= n; i++) {
            int L = i - k;
            int mid = L + k / 2;

            long long oldProfit = basePrefix[i] - basePrefix[L];
            long long newProfit = pricePrefix[i] - pricePrefix[mid];

            ans = max(ans, initialProfit - oldProfit + newProfit);
        }

        return ans;
    }
};
