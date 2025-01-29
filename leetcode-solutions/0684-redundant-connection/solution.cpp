class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int u,int v,vector<bool>&visited)
    {
        visited[u] = true;
        if(u==v)
        return true;

        for(auto &neighbour : adj[u])
        {
            if(visited[neighbour])
            continue;

            if(dfs(adj,neighbour,v,visited))
            {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        

        unordered_map<int,vector<int>>adj;

        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v  = edges[i][1];
            vector<bool>visited(edges.size(),false);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end()
                && dfs(adj,u,v,visited))
                {
                    return edges[i];
                }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
        
    }
};
