class Solution {
public:
    
    int solve(string&s1,string& s2 , int i, int j,vector<vector<int>>&dp)
    {
        if(i==s1.length() || j==s2.length())
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i]==s2[j])
        {
            return dp[i][j] =  1 + solve(s1,s2,i+1,j+1,dp);
        }
        else
        {
            return dp[i][j] = max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
        }
    }
    int solve2(string& s,int i, int j, vector<vector<int>>&dp)
    {
        if(i>j)
        return 0;
        if(i==j)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];

       
        if(s[i]==s[j])
        return dp[i][j] = 2 + solve2(s,i+1,j-1,dp);
        else
        {
            return dp[i][j] = max(solve2(s,i+1,j,dp),solve2(s,i,j-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // string s2 = s;
        // reverse(s2.begin(),s2.end());       // string s2(s.rbegin(),s.rend());
        
        // return solve(s,s2,0,0,dp);
        return solve2(s,0,n-1,dp);
    }
};
