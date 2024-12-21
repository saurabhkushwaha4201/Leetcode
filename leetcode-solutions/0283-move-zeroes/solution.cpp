class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i=0;
        int count=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==0)
            count++;
            else
            {
                nums[i]=nums[j];
                i++;
            }
        }
        for(int k = nums.size()-count;k<nums.size();k++)
        {
            nums[k]=0;
        }
        
    }
};
