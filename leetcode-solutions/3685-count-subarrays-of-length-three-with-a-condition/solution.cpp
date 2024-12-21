class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int first = nums[i];
            int sec = nums[i + 1];
            int third = nums[i + 2];

            if ((first + third) * 2 == sec) {
                count++;
            }
        }

        return count;
    }
};
