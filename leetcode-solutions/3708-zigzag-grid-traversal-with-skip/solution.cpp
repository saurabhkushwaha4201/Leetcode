class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        vector<int> temp;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            if(i%2==0)
            {
                for(int j = 0;j<m;j++)
                    {
                        temp.push_back(grid[i][j]);
                    }
            }
            else
            {
                for(int j = m-1;j>=0;j--)
                    {
                        temp.push_back(grid[i][j]);
                    }
            }
        }
        for(int j = 0;j<n*m;j+=2)
            {
                ans.push_back(temp[j]);
            }
        return ans;
    }
};

