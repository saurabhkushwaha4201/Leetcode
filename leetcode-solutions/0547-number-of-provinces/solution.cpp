class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, int v, vector<bool>& visited) {
        if (visited[v]) return; // If already visited, return

        visited[v] = true; // Mark the current node as visited

        // Explore all connected nodes (i.e., neighbors in the adjacency matrix)
        for (int u = 0; u < isConnected.size(); u++) {
            // If there's an edge between node v and node u, and u is not visited
            if (isConnected[v][u] == 1 && !visited[u]) {
                dfs(isConnected, u, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int provinces = 0;
        int vertices = isConnected.size();
        vector<bool>visited(vertices,false);
        for(int i =0;i<vertices;i++)
        {
            if(!visited[i])
            {
                dfs(isConnected,i,visited);
                provinces++;
            }
            
        }
        return provinces;
        
    }
};
