class Solution {
public:
    // int solve(int i, int j, int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp)
    // {
    //     if(i >= row || j >= col)
    //     {
    //         return INT_MAX;
    //     }


    //     if(i==(row-1) && j==(col-1))
    //     {
    //         return grid[i][j];
    //     }
    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }
    //     int down = solve(i+1,j,row,col,grid,dp);
    //     int right = solve(i,j+1,row,col,grid,dp);

    //     return dp[i][j] = grid[i][j] + min(down,right);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // vector<vector<int>>dp(row,vector<int>(col,-1));
        // return solve(0,0,row,col,grid,dp);

       // method - 2- Tabulation

       vector<vector<int>>dp(row,vector<int>(col));
        dp[0][0] = grid[0][0];
       // for first row 
       for(int j = 1;j<col;j++)
       {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        
       }

       // for first col
       for(int i = 1;i<row;i++)
       {
            dp[i][0] = grid[i][0] + dp[i-1][0];
       }

       // for rest of grid

       for(int i = 1;i<row;i++)
       {
            for(int j = 1;j<col;j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
       }
       return dp[row-1][col-1];

    }
};
