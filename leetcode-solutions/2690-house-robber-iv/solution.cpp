class Solution {
public:
    bool canPossible(vector<int>nums,int k,int mid)
    {
        int houses = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            {
                houses++;
                i++;
            }
        }
        return houses >=k;
    }
    int minCapability(vector<int>& nums, int k) 
    {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int result = -1;
        while(low<=high)
        {
            int mid = (low + high) / 2;
            if(canPossible(nums,k,mid))
            {
                result = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return result;
    }
};
