class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // Step 1: Create an adjacency list to store the graph.
        vector<vector<pair<int, int>>> adj(n);
        
        // Step 2: Fill the adjacency list with roads data.
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];  // Starting node of the road
            int v = roads[i][1];  // Ending node of the road
            int time = roads[i][2];  // Time to travel between u and v
            
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Step 3: Initialize constants and data structures.
        int mod = (int)(1e9 + 7);  // Modulo value to avoid overflow
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Change distance vector to long long to handle large values
        vector<long long> distance(n, LLONG_MAX);  // Use long long to store the shortest distances
        vector<int> ways(n, 0);
        
        // Starting point (node 0) has a distance of 0 and one way to reach itself
        distance[0] = 0;
        ways[0] = 1;

        // Step 4: Use Dijkstra's algorithm to find the shortest paths and count the number of distinct ways.
        pq.push({0, 0});  // Push the starting node with distance 0
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long dist = it.first;  // Current distance to the node
            int node = it.second; // The current node being processed
            
            // Explore all neighbors of the current node
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;  // Neighbor node
                int time = neighbor.second;    // Time to reach the neighbor node
                
                // Check if a shorter path to adjNode is found
                if (dist + time < distance[adjNode]) {
                    distance[adjNode] = dist + time;  // Update the shortest distance
                    pq.push({distance[adjNode], adjNode});
                    ways[adjNode] = ways[node];  // Update the number of ways to reach adjNode
                }
                // Check if another shortest path to adjNode is found
                else if (dist + time == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        // Step 5: Return the number of ways to reach the last node (node n-1), modulo 1e9 + 7
        return ways[n - 1] % mod;
    }
};

