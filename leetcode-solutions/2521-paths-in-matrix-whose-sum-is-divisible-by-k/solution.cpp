class Solution {
public:
    int m,n;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>& grid, int i, int j, int k,int currRem){
        if(i==m-1 && j==n-1){
            return (currRem + grid[i][j]) % k ==0 ? 1 : 0;
        }
        if(i>= m || j>=n){
            return 0;
        }
        if(dp[i][j][currRem]!=-1){
            return dp[i][j][currRem];
        }
        // right
        int right = solve(grid,i,j+1,k,(currRem + grid[i][j])%k);
        // down
        int down = solve(grid,i+1,j,k,(currRem + grid[i][j])%k);
        
        return dp[i][j][currRem] = (right + down)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return solve(grid,0,0,k,0);
    }
};
