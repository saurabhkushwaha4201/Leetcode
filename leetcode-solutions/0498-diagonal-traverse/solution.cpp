class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        map<int,vector<int>>mpp;

        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                mpp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int>results;
        bool flip = true;
        for(auto it:mpp)
        {
            if(flip)
            {
                reverse(it.second.begin(),it.second.end());
            }
            for(int val:it.second)
            {
                results.push_back(val);
            }
            flip = !flip;
        }
        return results;
    }
};
