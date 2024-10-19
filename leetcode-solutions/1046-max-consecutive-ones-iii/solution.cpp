class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int maxLength = 0;
        int left=0;
        int right=0;
        int zero=0;
        int len;
        while(right<nums.size())
        {
            if(nums[right]==0)
            {
                zero++;
            }
            if(zero > k)
            {
                if(nums[left]==0)
                {
                    zero--;
                }
                left++;
            }
            if(zero <= k )
            {
                len= right-left +1;
                maxLength= max(maxLength,len);
            }
            right++;
        }
        return maxLength;  
    }
};
