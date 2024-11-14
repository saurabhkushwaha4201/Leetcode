class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left=0;
        int right=0;
        int minLength=INT_MAX;
        int size=nums.size();
        int sum=0;
        while(right<size)
        {
            sum += nums[right];
            while(sum >= target)
            {
                minLength = min(minLength, right-left+1);
                sum -= nums[left];
                left++;
            }
           
            right++;
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
