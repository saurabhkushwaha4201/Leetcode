class Solution {
public:
//     struct Compare {
//     bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
//         return p1.second < p2.second;  // Compare based on the second element
//     }
// };
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int>mpp;
        for(auto num:nums)
        mpp[num]++;

        priority_queue<pair<int, int>> pq;
        for (const auto& elem : mpp) 
        {
            pq.push(make_pair(elem.second, elem.first));  // Reverse the pair: (second, first)
        }
        vector<int>ans;
        while(k-- && !pq.empty())
        {
            int top = pq.top().second;
            pq.pop();
            ans.push_back(top);
        }
        return ans;


        
        
        
    }
};
