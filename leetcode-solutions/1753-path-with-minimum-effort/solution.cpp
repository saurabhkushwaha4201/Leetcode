class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<P,vector<P>,greater<P>>pq;

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

        pq.push({0,{0,0}});// {diff,{row,col}}
        result[0][0] = 0;
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(auto &dir:directions)
            {
                int nRow = row + dir.first;
                int nCol = col + dir.second;

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n)
                {
                    int maxDiff = max(diff, abs(heights[row][col] - heights[nRow][nCol]));
                    if(result[nRow][nCol] > maxDiff)
                    {
                        result[nRow][nCol] = maxDiff;
                        pq.push({maxDiff,{nRow,nCol}});
                    }
                    
                }
            }
        }
        return result[m-1][n-1];
    }
};
