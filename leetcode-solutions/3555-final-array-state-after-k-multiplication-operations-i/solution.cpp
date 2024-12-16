class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            int index = pq.top().second;
            pq.pop();
            nums[index] = multiplier * nums[index];
            pq.push({nums[index],index});
        }
        return nums;
    }
};
