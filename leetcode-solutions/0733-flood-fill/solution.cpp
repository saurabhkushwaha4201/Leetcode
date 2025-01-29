class Solution {
public:
    // Depth-First Search (DFS) function to perform the flood fill
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& visited, int startColor) {
        // Define the 4 possible directions for moving in the grid: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Mark the current cell as visited
        visited[sr][sc] = 1;
        
        // Change the color of the current cell to the desired color
        image[sr][sc] = color;

        int n = image.size();    // Number of rows in the image (grid)
        int m = image[0].size(); // Number of columns in the image (grid)

        // Explore all 4 possible directions from the current cell
        for (const auto& dir : directions) {
            int nrow = sr + dir.first;  // New row after moving in the current direction
            int ncol = sc + dir.second; // New column after moving in the current direction

            // Check if the new position is valid, not visited yet, and has the same starting color
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  // Ensure the new position is within bounds
                && !visited[nrow][ncol]  // Ensure the cell has not been visited before
                && image[nrow][ncol] == startColor) {  // Ensure the cell has the same color as the start color
                    // Mark the new cell as visited
                    visited[nrow][ncol] = 1;
                    
                    // Perform DFS recursively to explore the connected region
                    dfs(image, nrow, ncol, color, visited, startColor);
                }
        }
    }

    // Main function to trigger the flood fill algorithm
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();       // Get the number of rows in the image
        int cols = image[0].size();    // Get the number of columns in the image
        
        // Store the original color of the starting cell (sr, sc)
        int startColor = image[sr][sc];
        
        // If the starting color is already the same as the new color, no filling is needed
        if (startColor == color) {
            return image;  // Return the image unchanged
        }

        // Create a visited matrix to keep track of the cells that have already been filled
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        // Start the DFS flood fill from the initial position (sr, sc)
        dfs(image, sr, sc, color, visited, startColor);
        
        // Return the modified image after the flood fill
        return image;
    }
};

