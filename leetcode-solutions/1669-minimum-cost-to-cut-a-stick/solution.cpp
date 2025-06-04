class Solution {
public:
    // int solve(vector<int>& cuts, int l, int r, vector<vector<int>>&dp)
    // {
    //     if(r-l<2)
    //     return 0;
    //     if(dp[l][r]!=-1)
    //     return dp[l][r];
    //     int result = INT_MAX;
    //     for(int i = l+1;i<=r-1;i++)
    //     {
    //         int cost = (cuts[r] - cuts[l]) + solve(cuts,l,i,dp) + solve(cuts,i,r,dp);
    //         result = min(result,cost);
    //     }
    //     return dp[l][r] = result;
    // }
    int minCost(int n, vector<int>& cuts) {
    // Step 1: Add stick boundaries (0 and n)
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0)); // dp[i][j] = min cost to cut between i and j

    // Process in reverse order: i from m-1 to 0
    for (int i = m - 1; i >= 0; i--) {
        for (int j = i + 2; j < m; j++) { // j must be at least i+2 so that there's space for a cut
            
            int minCost = INT_MAX;

            // Try all cut positions between i and j
            for (int k = i + 1; k < j; k++) {
                int cost = cuts[j] - cuts[i]; // cost of cutting the stick between cuts[i] and cuts[j]
                cost += dp[i][k];             // cost for left segment
                cost += dp[k][j];             // cost for right segment

                minCost = min(minCost, cost);
            }

            dp[i][j] = minCost;
        }
    }

    return dp[0][m - 1]; // Total min cost to cut from 0 to n
}
};
