class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) 
    {
        vector<vector<int>>distances(n+1,vector<int>(n+1,100000));
        for(int i =1;i<n;i++)
        {
            distances[i][i] = 0;
            distances[i][i+1] =1; 
            distances[i+1][i] = 1;

        }
        distances[x][y] = 1;
        distances[y][x] = 1;

        // floyd warshall
        for(int via = 1;via<=n;via++)
        {
            for(int i =1;i<=n;i++)
            {
                for(int j = 1;j<=n;j++)
                {
                    if(i==j)
                    continue;
                    else
                    {
                        distances[i][j] = min(distances[i][j], distances[i][via] + distances[via][j]);
                    }
                }
            }
        }
        vector<int>result(n);
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                if(i==j)
                continue;
                int val = distances[i][j];
                result[val-1]++;
            }
        }
        return result;

        
    }
};
