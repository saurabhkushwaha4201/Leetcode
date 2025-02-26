class Solution {
public:
    typedef pair<double,int>P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        priority_queue<P>pq;
        vector<vector<P>>adj(n);
        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({prob,v});
            adj[v].push_back({prob,u});
        }
        vector<double>result(n,0);
        result[start_node] = 1.0;
        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for(auto &neighbor : adj[node])
            {
                int v = neighbor.second;
                double weight = neighbor.first;
                if(prob*weight > result[v])
                {
                    result[v] = prob * weight;
                    pq.push({result[v],v});
                }
            }
        }
        return result[end_node];

        
    }
};
