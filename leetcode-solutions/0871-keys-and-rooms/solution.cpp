class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        queue<int>q;
        q.push(0);
        vector<bool>visited(rooms.size(),false);
        visited[0] = true;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto &v:rooms[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        for(auto vis:visited)
        {
            if(vis!=true)
            return false;
        }
        return true;
        
    }
};
