class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int start=0;
        int end=0;
        int count=0;
        int maxi=0;
        while(end<nums.size())
        {
            if(nums[end]==1)
            {
                count++;
                maxi=max(maxi,count);
            }
            else
            {
                count=0;
            }
            end++;
        }
        return maxi;
        
    }
};
