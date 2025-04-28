class Solution {
public:
    int n;
    int solve(vector<vector<int>>& grid,int r1,int c1, int c2, vector<vector<vector<int>>>&dp)
    {
        int r2 = r1 + c1 - c2;
        // out of bounds
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n)
        {
            return INT_MIN;
        }
        // thorn found
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return INT_MIN;

        // reached bottom right
        if(r1==n-1 && c1 == n-1)
        return grid[r1][c1];

        // already solved
        if(dp[r1][c1][c2]!=-1)
        return dp[r1][c1][c2];

        int cherries = 0;
        // if same cell
        if(r1==r2 && c1==c2)
        {
            cherries += grid[r1][c1];
        }
        else
        {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int ans = INT_MIN;
        // explore all 4 moves
        ans = max(ans,solve(grid,r1,c1+1,c2+1,dp)); // right,right
        ans = max(ans,solve(grid,r1+1,c1,c2+1,dp)); // down,right
        ans = max(ans,solve(grid,r1,c1+1,c2,dp));    // right,down
        ans = max(ans,solve(grid,r1+1,c1,c2,dp)); // down,down

        return dp[r1][c1][c2] = cherries + ans;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0, solve(grid, 0, 0, 0, dp));



    }
};
