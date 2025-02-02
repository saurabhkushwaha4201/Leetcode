class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list representation of the graph
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0]; // Course to take
            int b = prerequisites[i][1]; // Prerequisite course
            adj[b].push_back(a); // Create a directed edge from b to a (b → a)
        }

        vector<int>inDegree(numCourses,0);
        for(int i =0;i<numCourses;i++)
        {
            for(auto it: adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int>q;
        for(int i =0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }
        vector<int>result;
        while(!q.empty())
        {
            int u = q.front();
            result.push_back(u);
            q.pop();
            for(auto &v:adj[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                q.push(v);
            }
        }
        return result.size()==numCourses;
    }
};
