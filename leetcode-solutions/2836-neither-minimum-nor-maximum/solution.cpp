class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) 
    {
        priority_queue<int>maxHeap(nums.begin(),nums.end());
        priority_queue<int, vector<int>,greater<int>>minHeap(nums.begin(),nums.end());
        int maxi = maxHeap.top();
        int mini = minHeap.top();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=maxi && nums[i]!= mini)
            return nums[i];
        }
        return -1;
        
    }
};
