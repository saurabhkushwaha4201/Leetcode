class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();
        int maj = -1;
        int count = 0;
        for(auto num:nums)
        {
            if(count==0)
            {
                maj = num;
                count = 1;
            }
            else if(num==maj)
            {
                count++;
            }
            else
            count--;
        }

        int majCount = 0;
        for(auto num:nums)
        {
            if(num==maj)
            {
                majCount++;
            }
        }
        count = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]==maj)
            {
                count++;
            }
            int remainingCount = majCount - count;

            int n1 = i+1;
            int n2 = n-i-1;
            if(count > n1/2 && remainingCount > n2/2)
            {
                return i;
            }
        }
        return -1;
        
    }
};
