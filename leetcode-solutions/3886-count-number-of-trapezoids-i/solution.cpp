class Solution {
public:
    const int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        unordered_map<int,int>mpp;
        for(int i = 0;i<n;i++){
            int y = points[i][1];
            mpp[y]++;
        }
        long long totalEdge = 0;
        for(auto it:mpp){
            int freq = it.second;
            int currEdge =1LL*freq*(freq-1)/2;
            ans = (ans + 1LL*currEdge*totalEdge)%mod;
            totalEdge += currEdge;
        }
        return ans;
    }
};
