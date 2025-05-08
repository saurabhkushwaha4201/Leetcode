class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>>minTime(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;

        pq.push({0,{0,0}});
        minTime[0][0] = 0;

        while(!pq.empty())
        {
            int currTime = pq.top().first;
            int currRow = pq.top().second.first;
            int currCol = pq.top().second.second;
            pq.pop();

            if(currRow == m-1 && currCol == n-1)
            return minTime[currRow][currCol];

            for(auto dir:directions)
            {
                int nRow = currRow + dir.first;
                int nCol = currCol + dir.second;

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n)
                {
                    int moveCost = ((nRow + nCol)%2 == 0) ? 2 : 1;
                    int waitTime  = max((moveTime[nRow][nCol] - currTime),0 );

                    int newTime = waitTime + currTime + moveCost;
                    if(minTime[nRow][nCol]>newTime)
                    {
                        minTime[nRow][nCol] = newTime;
                        pq.push({newTime,{nRow,nCol}});
                    }
                }
            }

        }

        return minTime[m-1][n-1];
    }
};
