class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size()+1;
        int MOD = 1000000007;
        vector<vector<pair<int,int>>>adj(n);
        for(auto & edge : conversions)
            {
                int u = edge[0];
                int v= edge[1];
                int weight = edge[2];
                adj[u].push_back({v,weight});
            }
        vector<int>ans(n);
        ans[0] = 1;
        queue<int>q;
        q.push(0);
        while(!q.empty())
            {
                int u = q.front();
                long long value = ans[u];
                q.pop();
                for(auto neigh : adj[u])
                    {
                        int v = neigh.first;
                        int weight = neigh.second;
                        ans[v] = (int)(value * weight % MOD);
                        q.push(v);
                    }
            }
        return ans;
    }
};
