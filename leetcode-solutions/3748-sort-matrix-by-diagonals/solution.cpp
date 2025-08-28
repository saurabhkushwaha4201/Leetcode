class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        map<int,vector<int>>mpp;
        vector<vector<int>>result(grid.size(),vector<int>(grid[0].size()));
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                mpp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it:mpp)
        {
            int key= it.first;
            if(key<0)
            sort(it.second.begin(),it.second.end());
            else
            sort(it.second.rbegin(),it.second.rend());
        }
        for(int i =grid.size()-1;i>=0;i--)
        {
            for(int j = grid[0].size()-1;j>=0;j--)
            {
                result[i][j] = mpp[i-j].back();
                mpp[i-j].pop_back();
            }
        }
        return result;

    }
};
