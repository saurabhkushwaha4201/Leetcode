#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[301][301]; // dp[n][i] — minimal state

    int powi(int i,int x)
    {
        return pow(i,x);
    }
    int solve(int n, int x, int i) {
        if (n == 0) return 1; // found valid way
        int p = powi(i, x);
        if (p > n) return 0; // can't use this number

        if (dp[n][i] != -1) return dp[n][i]; // memoization with i included

        int take = solve(n - p, x, i + 1); // take current number
        int notTake = solve(n, x, i + 1);  // skip current number

        return dp[n][i] = (take + notTake)%MOD;
    }
    
    int numberOfWays(int n, int x) {
        // memset(dp, -1, sizeof(dp));
        // return solve(n, x, 1);

        vector<long long>dp(n+1,0);

        dp[0] = 1;
        for(int i = 1;i<=n;i++)
        {
            long long val = powi(i,x);
            if(val>n)
            break;

            for(int j = n;j>=val;j--)
            {
                dp[j] = (dp[j] + dp[j-val])%MOD;
            }
        }
        return dp[n];

        
    }
};

