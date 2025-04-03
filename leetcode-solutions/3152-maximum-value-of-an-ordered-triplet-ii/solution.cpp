class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long result = 0;
        long long maxEle = 0;
        long long maxDiff = 0;
        for(int i =0;i<nums.size();i++)
        {
            result = max(result,(maxDiff*nums[i]));
            maxDiff = max(maxDiff,maxEle - nums[i]);
            maxEle = max(maxEle,(long long)nums[i]);

        }
        return result;
        
    }
};
