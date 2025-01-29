class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) 
    {
        // Get the number of rows and columns in the grid
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize the distance grid with -1, which will represent unvisited cells
        vector<vector<int>> dist(rows, vector<int>(cols, -1));

        // Directions for the four possible moves (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Queue for the Breadth-First Search (BFS), used to process cells
        queue<pair<int, int>> q;

        // Step 1: Initialize the queue with all the cells that are 0
        // Set their distance to 0 because their distance to themselves is 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {  // If the cell contains 0
                    q.push({i, j});  // Add to the BFS queue
                    dist[i][j] = 0;  // Distance of 0 cells to themselves is 0
                }
            }
        }

        // Step 2: Perform BFS to update the distance grid for all cells
        while (!q.empty()) {
            int row = q.front().first;  // Row of the current cell
            int col = q.front().second; // Column of the current cell
            q.pop(); // Pop the current cell from the queue

            // Step 3: Check all four possible directions (up, down, left, right)
            for (const auto& dir : directions) {
                int nrow = row + dir.first;  // Calculate new row position
                int ncol = col + dir.second; // Calculate new column position

                // Step 4: Check if the new position is within bounds and not yet visited
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && dist[nrow][ncol] == -1) {
                    dist[nrow][ncol] = dist[row][col] + 1;  // Update the distance
                    q.push({nrow, ncol});  // Push the new cell into the queue for further exploration
                }
            }
        }

        // Step 5: Return the updated distance grid
        return dist;
    }
};

