class Solution {
public:
    typedef pair<int,pair<int,int>>PP;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int rows  = heightMap.size();
        int cols = heightMap[0].size();

        priority_queue<PP,vector<PP>,greater<>>boundaryCells;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));

        // left most column and right most column (0,cols-1)

        for (int r = 0; r < rows; ++r) {
            for (int c : {0, cols - 1}) { //0 : left most boundary, cols-1 right most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        // top row and bottom row (0,rows-1)

        for (int c = 0; c < cols; ++c) {
            for (int r : {0, rows - 1}) { //0 : top most boundary, rows-1 bottom most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }
        
        int trappedRain = 0;

        while(!boundaryCells.empty())
        {
            auto [height, cell] = boundaryCells.top();
            boundaryCells.pop();

            int i = cell.first;
            int j = cell.second;

            // find neighbours
            for(vector<int>&dir : directions)
            {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < rows && j_ >= 0 && j_ < cols && !visited[i_][j_])
                {
                    trappedRain += max(0, height - heightMap[i_][j_]);
                    
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});

                    
                    visited[i_][j_] = true;
                }
            }
        }
        return trappedRain;
    }
};
