class Solution {
public:
    int solve(vector<int>& cuts, int l, int r, vector<vector<int>>&dp)
    {
        if(r-l<2)
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        int result = INT_MAX;
        for(int i = l+1;i<=r-1;i++)
        {
            int cost = (cuts[r] - cuts[l]) + solve(cuts,l,i,dp) + solve(cuts,i,r,dp);
            result = min(result,cost);
        }
        return dp[l][r] = result;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        n = cuts.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return solve(cuts,0,n-1,dp);
    }
};
