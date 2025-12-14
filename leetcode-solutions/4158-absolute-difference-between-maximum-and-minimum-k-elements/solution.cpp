class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long minSum = 0, maxSum = 0;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            minSum += nums[i];
            maxSum += nums[n - 1 - i];
        }

        return abs(maxSum - minSum);
    }
};
