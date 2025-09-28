class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = n-1;i>=2;i--){
            if(nums[i-2]+nums[i-1]>nums[i] && (nums[i] > 0 && nums[i-1] > 0 && nums[i-2] > 0)){
                return nums[i-2]+nums[i-1]+nums[i];
            }
        }
        return 0;
    }
};
