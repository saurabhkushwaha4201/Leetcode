class Solution {
public:
    typedef pair<int, pair<int, int>> P;  // cost, (x, y)
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Priority queue for Dijkstra's algorithm (min-heap)
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        
        // Result matrix to store the minimum cost to reach each cell
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;

        // Directions: right, left, down, up
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int currCost = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // Iterate through the four possible directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];

                // Ensure the new position is within bounds
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    // Determine the cost of moving in the current direction
                    int gridDir = grid[x][y] - 1;  // Convert grid direction to 0-based index
                    int moveCost = (gridDir == i) ? 0 : 1;  // If the direction matches, no cost; otherwise, 1
                    int newCost = currCost + moveCost;

                    // If the new cost is better, update and push the new state into the priority queue
                    if (newCost < result[newX][newY]) {
                        result[newX][newY] = newCost;
                        pq.push({newCost, {newX, newY}});
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner
        return result[m - 1][n - 1];
    }
};

