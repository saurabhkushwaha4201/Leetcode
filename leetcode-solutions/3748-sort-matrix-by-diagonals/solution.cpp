class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

    // Function to extract and sort diagonals
    auto sortDiagonal = [&](int row, int col, bool reverse) {
        vector<int> diagonal;
        int r = row, c = col;
        // Collect diagonal elements
        while (r < n && c < n) {
            diagonal.push_back(grid[r][c]);
            r++;
            c++;
        }
        // Sort the diagonal
        if (reverse) {
            sort(diagonal.rbegin(), diagonal.rend()); // non-increasing order
        } else {
            sort(diagonal.begin(), diagonal.end()); // non-decreasing order
        }
        
        // Put the sorted elements back into the grid
        r = row, c = col;
        int i = 0;
        while (r < n && c < n) {
            grid[r][c] = diagonal[i++];
            r++;
            c++;
        }
    };

    // Sort bottom-left triangle diagonals in non-increasing order
    for (int i = 0; i < n; i++) {
        sortDiagonal(i, 0, true);  // Sort diagonals starting from row i, col 0 in non-increasing order
    }

    // Sort top-right triangle diagonals in non-decreasing order
    for (int j = 1; j < n; j++) {
        sortDiagonal(0, j, false); // Sort diagonals starting from row 0, col j in non-decreasing order
    }

    return grid;
    }
};
