class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int required_sum = total_sum - x;
        
        // If required_sum is 0, the entire array must be removed
        if (required_sum == 0) return nums.size();
        
        int left = 0, current_sum = 0, max_len = -1;
        
        // Use sliding window to find the longest subarray with sum equal to required_sum
        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];
            
            // Shrink the window from the left if the current sum exceeds the required sum
            while (current_sum > required_sum && left <= right) {
                current_sum -= nums[left++];
            }
            
            // Check if we've found a subarray with the required sum
            if (current_sum == required_sum) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        // If max_len is found, the minimum number of operations is the complement of the subarray length
        if (max_len != -1) {
            return nums.size() - max_len;
        }
        
        return -1; // Return -1 if no such subarray is found
    }
};

