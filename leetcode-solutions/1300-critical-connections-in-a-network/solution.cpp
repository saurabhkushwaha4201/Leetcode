
class Solution {
public:
    int count = 1;  // Global variable to keep track of the discovery time of each node

    // Depth First Search function to explore the graph and find bridges
    void dfs(int node, int parent, unordered_map<int, vector<int>>& adj, 
             vector<int>& time, vector<int>& low, vector<bool>& visited, 
             vector<vector<int>>& bridges) {

        visited[node] = true;  // Mark the current node as visited
        low[node] = time[node] = count;  // Set the time and low value of the current node
        count++;  // Increment the global counter (used for discovery times)

        // Explore all the neighbors of the current node
        for (auto neigh : adj[node]) {
            if (neigh == parent) continue;  // Skip the edge that leads to the parent node (to avoid revisiting the parent)

            if (visited[neigh]) {
                // If the neighbor is already visited, it means it's a back edge. 
                // Update the low value for the current node using the neighbor's low value
                low[node] = min(low[node], low[neigh]);
            } else {
                // If the neighbor is not visited, recursively explore it
                dfs(neigh, node, adj, time, low, visited, bridges);

                // After returning from recursion, update the low value for the current node
                low[node] = min(low[node], low[neigh]);

                // If the low value of the neighbor is greater than the discovery time of the current node,
                // it means the edge (node, neigh) is a bridge (critical connection)
                if (low[neigh] > time[node]) {
                    bridges.push_back({node, neigh});  // Add the bridge to the result
                }
            }
        }
    }

    // Main function to find all the critical connections (bridges) in the graph
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;  // Adjacency list representation of the graph

        // Build the adjacency list from the given connections
        for (const auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<bool> visited(n, false);  // To keep track of visited nodes
        vector<int> time(n, 0);  // Discovery time for each node
        vector<int> low(n, 0);  // Lowest reachable time for each node
        vector<vector<int>> bridges;  // To store the critical connections (bridges)

        // Start DFS from each unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, time, low, visited, bridges);  // Call DFS for unvisited node, with -1 as parent (for the root)
            }
        }

        return bridges;  // Return the list of bridges (critical connections)
    }
};

