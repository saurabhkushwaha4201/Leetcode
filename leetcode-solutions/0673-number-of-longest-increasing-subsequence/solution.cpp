class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // dp[i]: length of LIS ending at index i
        vector<int> length(n, 1);
        // count[i]: number of LIS ending at index i
        vector<int> count(n, 1);

        int maxLen = 1;  // Keep track of the maximum LIS length found

        // Loop over each index i
        for (int i = 0; i < n; ++i) {
            // Look at all elements before i
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        // Found a better/longer LIS ending at i via j
                        length[i] = length[j] + 1;
                        count[i] = count[j];  // Start fresh with count from j
                    } else if (length[j] + 1 == length[i]) {
                        // Found another LIS of same max length ending at i
                        count[i] += count[j];  // Add more ways
                    }
                }
            }
            // Update the overall maximum LIS length seen so far
            maxLen = max(maxLen, length[i]);
        }

        int totalWays = 0;
        // Sum all counts where the LIS length equals maxLen
        for (int i = 0; i < n; ++i) {
            if (length[i] == maxLen) {
                totalWays += count[i];
            }
        }

        return totalWays;
    }
};
