class Solution {
public:
    int m,n;
    // int solve(vector<vector<char>>&matrix, int i, int j, vector<vector<int>>&dp)
    // {
    //     if(i>=m || j>= n)
    //     {
    //         return 0;
    //     }
    //     if(matrix[i][j]=='0')
    //     return 0;
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];

    //     int right = solve(matrix,i,j+1,dp);
    //     int down = solve(matrix,i+1,j,dp);
    //     int diagonal = solve(matrix,i+1,j+1,dp);

    //     return dp[i][j] = 1 + min({down,right,diagonal});
    // }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int result = 0;
        // for(int i = 0;i<m;i++)
        // {
        //     for(int j = 0;j<n;j++)
        //     {
        //         if(matrix[i][j]=='1')
        //         {
        //             result = max(result,solve(matrix,i,j,dp));
        //         }
        //     }
        // }
        // return result*result;

        vector<vector<int>>dp(m,vector<int>(n,0));
        int result =0;
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==m-1 || j==n-1)
                {
                    dp[i][j] = matrix[i][j] -'0';
                }
                else if(matrix[i][j] =='1')
                {
                    dp[i][j] = 1 + min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                }
                result = max(result,dp[i][j]);
            }
        }
        return result * result;
    }
};
