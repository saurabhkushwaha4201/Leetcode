class Solution {
public:
    vector<int> size;
    vector<int> parent;
    
    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unionBysize(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else if (size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(n * m);
        size.resize(n * m, 1);

        // Initialize parent for each cell
        for(int i = 0; i < n * m; i++) {
            parent[i] = i;
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Union adjacent '1's
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    for(auto &dir : directions) {
                        int adjRow = row + dir.first;
                        int adjCol = col + dir.second;

                        if(adjRow >= 0 && adjRow < m && adjCol >= 0 && adjCol < n && grid[adjRow][adjCol] == 1) {
                            int node = row * n + col;
                            int adjNode = adjRow * n + adjCol;
                            if(find(node) != find(adjNode)) {
                                unionBysize(node, adjNode);
                            }
                        }
                    }
                }
            }
        }

        int maxIslands = 0;

        // Now check for the largest possible island when changing a 0 to 1
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) {
                    set<int> components;
                    // Look at all adjacent '1' cells and collect their components
                    for(auto &dir : directions) {
                        int adjRow = row + dir.first;
                        int adjCol = col + dir.second;

                        if(adjRow >= 0 && adjRow < m && adjCol >= 0 && adjCol < n && grid[adjRow][adjCol] == 1) {
                            int adjNode = adjRow * n + adjCol;
                            components.insert(find(adjNode));
                        }
                    }
                    int totalSize = 1; // The new cell itself
                    for(auto it : components) {
                        totalSize += size[it]; // Add the size of all connected components
                    }
                    maxIslands = max(maxIslands, totalSize); // Track the largest island size
                }
            }
        }

        // Finally, consider the case where the largest island is formed by already existing '1's
        for(int i = 0; i < n * m; i++) {
            maxIslands = max(maxIslands, size[find(i)]);
        }

        return maxIslands;
    }
};

