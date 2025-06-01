class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Sort the input to ensure a divides b implies a <= b
        sort(nums.begin(), nums.end());

        // Step 2: dp[i] stores the length of the largest divisible subset ending at index i
        vector<int> dp(n, 1);

        // Step 3: parent[i] will help us reconstruct the subset path (stores previous index)
        vector<int> parent(n, -1);

        int maxLength = 1;     // To track the maximum length found so far
        int lastIndex = 0;     // To track the last index of the max subset

        // Step 4: Build the dp and parent array using a nested loop
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If nums[i] is divisible by nums[j], it can extend the subset
                if (nums[i] % nums[j] == 0) {
                    // Update dp[i] if we found a longer subset ending at i
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j; // Store index j as the parent of i
                    }
                }
            }
            // Update global maximum length and its last index
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        // Step 5: Reconstruct the subset using the parent array
        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex]; // Move to the previous element in the chain
        }

        // The result is built in reverse order, reverse it if needed
        // reverse(result.begin(), result.end()); // Optional

        return result;
    }
};

