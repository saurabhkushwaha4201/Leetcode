class Solution {
public:
    int solve(vector<int>& stones,int index,int sum,int weights, vector<vector<int>>&dp)
    {
        if(index>=stones.size())
        return 0;

        if(dp[index][sum]!=-1)
        return dp[index][sum];

        int pick = INT_MIN;
        if(sum + stones[index]<=weights/2)
        pick = stones[index] + solve(stones,index+1,sum + stones[index],weights,dp);
        int notPick = solve(stones,index+1,sum,weights,dp);
        
        return dp[index][sum] = max(pick,notPick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int weights = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(weights/2 + 1, -1));
        int best =  solve(stones,0,0,weights,dp);
        return weights - 2*best;
    }
};
