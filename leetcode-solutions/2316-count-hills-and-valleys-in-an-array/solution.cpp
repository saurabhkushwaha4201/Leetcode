class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        int count = 0;
        while(j+1<n)
        {
            if((nums[i]<nums[j] && nums[j+1]<nums[j]) ||(nums[i]>nums[j] && nums[j+1]>nums[j]))
            {
                count++;
                i=j;
            }
            j++;
        }
        return count;
    }

};
