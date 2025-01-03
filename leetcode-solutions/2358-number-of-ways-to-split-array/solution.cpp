class Solution {
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        long long  prefixSum = accumulate(nums.begin(),nums.end(),0LL);
        int validSplit=0;
        long long preSum = 0;
       // long long endSum = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            preSum += nums[i];
           // endSum = prefixSum - preSum;
            if(preSum>=(prefixSum - preSum))
            {
                validSplit++;
            }
        }
        return validSplit;
        
    }
};
