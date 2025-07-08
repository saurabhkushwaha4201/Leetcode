class Solution {
public:
    int solve(vector<vector<int>>& events, int k, int n, int index, vector<vector<int>>&dp)
    {
        if(index>=n || k==0)
        {
            return 0;
        }

        if(dp[index][k]!=-1)
        return dp[index][k];

        int startDay = events[index][0];
        int endDay = events[index][1];
        int value = events[index][2];
        int skip = solve(events,k,n,index+1,dp);
        int j = index +1;
  
        while (j < n && events[j][0] <= endDay) {
            j++;
        }

        int take = value + solve(events,k-1,n,j,dp);

        return dp[index][k] = max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n  = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(events,k,n,0,dp);
    }
};
