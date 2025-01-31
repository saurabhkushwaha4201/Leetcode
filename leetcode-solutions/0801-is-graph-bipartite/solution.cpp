class Solution {
public:
    bool isBipartiteDfs(vector<vector<int>>& graph, int currNode, vector<int>& color,int currColor) {
        color[currNode] = currColor; // Start coloring the first node with color 0

        for (auto &neighbor : graph[currNode]) {
                if (color[neighbor] == -1) { // If not colored, color with opposite color
                    if(isBipartiteDfs(graph,neighbor,color,1 - color[currNode])==false)
                    {
                        return false;
                    }
                    
                } 
                else if (color[neighbor] == color[currNode]) { // If same color, it's not bipartite
                    return false;
                }
            }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int vertices = graph.size();
        vector<int> color(vertices, -1); // Initialize all nodes as uncolored (-1)

        for (int i = 0; i < vertices; i++) {
            if (color[i] == -1) { // If not visited, check for bipartiteness
                if (!isBipartiteDfs(graph, i, color,0)) {
                    return false;
                }
            }
        }
        return true;
    }
};

