class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k=0;
        if(nums.size()==0)
        return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[k])            //pichle wale se compare
            {
                k++;
                nums[k]=nums[i];        
            }
        }
        return (k+1);       // phla element bhi include hoga
    }
};
