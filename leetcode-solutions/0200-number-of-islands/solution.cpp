class Solution {
public:
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& grid,int row,int col ,vector<vector<int>>&visited )
    {
        visited[row][col] = 1;
        for(auto &dir:directions)
        {
            int nrow  = row + dir.first;
            int ncol = col + dir.second;

            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()
                && visited[nrow][ncol]==0 && grid[nrow][ncol]=='1')
                {
                    dfs(grid,nrow,ncol,visited);
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>>visited(rows,vector<int>(cols,0));
        int count = 0;
        for(int i =0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    dfs(grid,i,j,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
