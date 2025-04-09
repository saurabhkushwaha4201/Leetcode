class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            if(nums[i]<k)
            return -1;
            if(nums[i]!=k)
            mpp[nums[i]]++;
        }
        return mpp.size();
    }
};
