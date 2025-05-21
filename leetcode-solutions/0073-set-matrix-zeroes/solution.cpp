class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m =  matrix.size();
        int n = matrix[0].size();
        unordered_set<int>stRow;
        unordered_set<int>stCol;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    stRow.insert(i);
                    stCol.insert(j);
                }
            }
        }

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(stRow.find(i)!=stRow.end() ||stCol.find(j)!=stCol.end() )
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};
