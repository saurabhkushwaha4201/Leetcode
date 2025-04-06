class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int minIndex = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                int pairSum = nums[i] + nums[i + 1];
                if (pairSum < minSum) {
                    minSum = pairSum;
                    minIndex = i;
                }
            }
            nums[minIndex] = minSum;
            nums.erase(nums.begin() + minIndex + 1);
            operations++;
        }
        return operations;
    }
};
