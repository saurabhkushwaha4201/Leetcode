class Solution {
public:
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board,int row,int col,vector<vector<int>>&visited)
    {
        visited[row][col] = 1;
        
        for(const auto &dir : directions)
        {
            int nrow = row + dir.first;
            int ncol = col + dir.second;
            
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size()
                && visited[nrow][ncol]==0 && board[nrow][ncol]=='O')
                {
                    dfs(board,nrow,ncol,visited);
                }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        
        // for top and bottome row
        for(int j =0;j<cols;j++)
        {
            if(board[0][j]=='O' && visited[0][j]==0)
            {
                dfs(board,0,j,visited);
            }
            if(board[rows-1][j]=='O' && visited[rows-1][j]==0)
            {
                dfs(board,rows-1,j,visited);
            }
        }
        
        // for first and last column
        for(int i =0;i<rows;i++)
        {
            if(board[i][0]=='O' && visited[i][0]==0)
            {
                dfs(board,i,0,visited);
            }
            
            if(board[i][cols-1]=='O' && visited[i][cols-1]==0)
            {
                dfs(board,i,cols-1,visited);
            }
        }
        
        for(int i =0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if(board[i][j]=='O' && visited[i][j]==0)
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
