class Solution {
public:
    bool dfs(vector<int>&arr,int start,vector<int>&visited){
        if(start>=arr.size()||start<0)
        return false;
        if(visited[start]==true)
        return false;
        if(arr[start]==0)
        return true;
        visited[start] = true;
        int jump1 = start + arr[start];
        int jump2 = start - arr[start];
        return dfs(arr,jump1,visited) || dfs(arr,jump2,visited);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>visited(n+1,false);
        // return dfs(arr,start,visited);
        queue<int> q;
        q.push(start);
        visited[start] = true;   // mark at push time

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (arr[idx] == 0)
                return true;

            int jump1 = idx + arr[idx];
            int jump2 = idx - arr[idx];

            if (jump1 >= 0 && jump1 < n && !visited[jump1]) {
                q.push(jump1);
                visited[jump1] = true;
            }
            if (jump2 >= 0 && jump2 < n && !visited[jump2]) {
                q.push(jump2);
                visited[jump2] = true;
            }
        }
        return false;
    }
};
