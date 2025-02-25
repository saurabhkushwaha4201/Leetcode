class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i]);
    }

    void unionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;  // attach y_parent to x_parent
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;  // attach x_parent to y_parent
        } else {
            parent[y_parent] = x_parent;  // arbitrarily attach y_parent to x_parent
            rank[x_parent] += 1;           // increase rank of the new root
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(find(u)!=find(v))
            {
                unionByRank(u,v);
            }
        }
        unordered_map<int, int> componentSize;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            componentSize[root]++;
        }
        long long totalPairs = (long long)n * (n-1)/2;
        long long reachablePair = 0;
        for (auto& it : componentSize) {
            int size = it.second;
            reachablePair += (long long)size * (size - 1) / 2;
        }
        return totalPairs - reachablePair;

        
    }
};
