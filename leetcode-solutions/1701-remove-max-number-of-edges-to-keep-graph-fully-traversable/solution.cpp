class Solution {
public:
    // vector<int> parent;
    // vector<int> rank;
    static bool compareEdges(const vector<int>& e1, const vector<int>& e2) {
    return e1[0] > e2[0];  // Sort based on the first element in decreasing order
}
    int find(int i,vector<int>&parent) {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i],parent);
    }

    void unionByRank(int x, int y,vector<int>&rank,vector<int>&parent) {
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);

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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        vector<int>aliceParent(n+1);
        vector<int>aliceRank(n+1,0);
        vector<int>bobParent(n+1);
        vector<int>bobRank(n+1,0);
        for(int i =1;i<=n;i++)
        {
            aliceParent[i] = i;
            bobParent[i] = i;
        }
    
        sort(edges.begin(), edges.end(), compareEdges);
        int count = 0;
        for(int i =0;i<edges.size();i++)
        {
            int u = (edges[i][1]);
            int v  = (edges[i][2]);

            if(edges[i][0]==3)
            {
                bool aliceUnion = (find(u, aliceParent) != find(v, aliceParent));
                bool bobUnion = (find(u, bobParent) != find(v, bobParent));
                if (aliceUnion) {
                    unionByRank(u, v, aliceRank, aliceParent);
                    
                }
                if (bobUnion) {
                    unionByRank(u, v, bobRank, bobParent);
                }
                if(!aliceUnion && !bobUnion)
                count++;
            }
            if(edges[i][0]==2)
            {
                if(find(u,bobParent) != find(v,bobParent))
                {
                    unionByRank(u,v,bobRank,bobParent);
                }
                else
                count++;
            }
            if(edges[i][0]==1)
            {
                if(find(u,aliceParent) != find(v,aliceParent))
                {
                    unionByRank(u,v,aliceRank,aliceParent);
                }
                else
                count++;
            }
        }

        for (int i = 2; i <= n; i++) {
            if (find(i, aliceParent) != find(1, aliceParent) || find(i, bobParent) != find(1, bobParent)) {
                return -1;
            }
        }
        return count;
    }
};
