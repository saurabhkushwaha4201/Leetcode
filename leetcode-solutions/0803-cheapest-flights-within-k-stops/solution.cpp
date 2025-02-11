class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        // Create an adjacency list to represent the graph (each node has a list of pairs {neighbor, cost})
        vector<vector<pair<int, int>>> adj(n);
        
        // Populate the adjacency list with the flight data from 'flights' vector
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];    // Source node of the flight
            int v = flights[i][1];    // Destination node of the flight
            int cost = flights[i][2]; // Cost of the flight
            adj[u].push_back({v, cost}); // Add edge (v, cost) from node u to the adjacency list
        }

        // Queue to perform BFS, storing pairs of (node, cost to reach that node)
        queue<pair<int, int>> q;
        q.push({src, 0}); // Start with the source node 'src' and 0 cost to reach it
        
        // Vector to store the minimum distance (cost) to reach each node
        vector<int> distance(n, INT_MAX);  // Initialize all distances as infinity
        distance[src] = 0; // The distance to the source node is 0
        
        // Variable to track the number of stops we've made (including the source node)
        int steps = 0;
        
        // Perform a BFS to explore all nodes within 'k' stops
        while (!q.empty() && steps <= k) {
            int size = q.size(); // Get the number of nodes to process at the current level (same number of stops)

            // Process all nodes at the current level (same number of stops)
            while (size--) {
                // Get the current node and the cost to reach it
                int dist = q.front().second;
                int node = q.front().first;
                q.pop();

                // Explore all neighbors of the current node
                for (auto &neighbor : adj[node]) {
                    int adjNode = neighbor.first; // The neighboring node
                    int cost = neighbor.second;   // The cost to reach the neighboring node

                    // If traveling to adjNode through the current node results in a cheaper cost
                    if (dist + cost < distance[adjNode]) {
                        distance[adjNode] = dist + cost; // Update the minimum cost to reach adjNode
                        q.push({adjNode, distance[adjNode]}); // Push the updated node and its cost into the queue
                    }
                }
            }

            steps++; // Increment the stop count after processing one level
        }

        // If we haven't found a valid path to the destination, return -1
        if (distance[dst] == INT_MAX)
            return -1;

        // Otherwise, return the minimum cost to reach the destination
        return distance[dst];
    }
};

