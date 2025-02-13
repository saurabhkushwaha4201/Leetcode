class Solution {
public:
    // Function to count the city with the least reachable cities
    int leastReachable(int n, vector<vector<int>>& distance, int distanceThreshold) {
        int resultCity = -1;
        int leastReach = INT_MAX; // Initialize with a large value

        for (int i = 0; i < n; i++) {
            int countReach = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && distance[i][j] <= distanceThreshold) {
                    countReach++;
                }
            }

            // Select the city with the least reachable cities, or if tied, the one with the highest index
            if (countReach <= leastReach) {
                leastReach = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }

    // Bellman-Ford Algorithm to find the shortest paths
    void bellmanFord(int n, vector<vector<int>>& edges, vector<int>& result, int src) {
        // Initialize result array to INT_MAX
        fill(result.begin(), result.end(), INT_MAX);
        result[src] = 0; // Distance to itself is 0

        // Relax all edges (n-1) times
        for (int count = 1; count <= n - 1; count++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int cost = edge[2];

                if (result[u] != INT_MAX && result[u] + cost < result[v]) {
                    result[v] = result[u] + cost;
                }
                if (result[v] != INT_MAX && result[v] + cost < result[u]) {
                    result[u] = result[v] + cost;
                }
            }
        }
    }

    // Main function to find the city with the least reachable cities
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix with infinity
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        
        // Step 2: Set the edge distances in the distance matrix
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            distance[u][v] = weight;
            distance[v][u] = weight; // Since it's undirected
        }

        // Step 3: Set the diagonal elements to 0 (distance from a node to itself is 0)
        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }

        // Step 4: Run Bellman-Ford from each city
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, distance[i], i);
        }

        // Step 5: Find the city with the least number of reachable cities within the distance threshold
        return leastReachable(n, distance, distanceThreshold);
    }
};

