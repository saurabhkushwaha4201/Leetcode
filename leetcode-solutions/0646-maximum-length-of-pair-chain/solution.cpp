class Solution {
public:
    int solve(vector<vector<int>>& pairs, int index, int prevIndex, vector<vector<int>>&dp)
    {
        if(index==pairs.size())
        {
            return 0;
        }
        if(dp[index][prevIndex+1]!=-1)
        {
            return dp[index][prevIndex+1];
        }
        int take = 0;
        if(prevIndex == -1 || pairs[prevIndex][1] < pairs[index][0])
        {
            take = 1 + solve(pairs,index+1, index, dp);
        }
        int notTake = solve(pairs, index+1, prevIndex, dp);

        return dp[index][prevIndex+1] =  max(take,notTake);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(pairs,0,-1,dp);
        // vector<int>dp(n,1);
        // int maxLen = 1;
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = 0;j<i;j++)
        //     {
        //         if(pairs[j][1] < pairs[i][0])
        //         {
        //             dp[i] = max(dp[i],dp[j]+1);
        //         }
        //     }
        //     maxLen = max(maxLen,dp[i]);
        // }
        // return maxLen;
    }
};
