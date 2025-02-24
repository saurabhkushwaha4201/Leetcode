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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        
        // Initialize parent of each node to itself.
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (find(u) != find(v)) {
                unionByRank(u, v);
            } else {
                result = {u, v};  // Save the last redundant edge
            }
        }
        return result;
    }
};

