class Solution {
public:
    vector<vector<int>> result;  // To store the final result (all unique triplets)

    // Helper function to find pairs that sum up to the target
    void twoSum(vector<int>& nums, int target, int i, int j) {
        while (i < j) {  // Use two pointers to check pairs
            // If the sum of the current pair is greater than the target, move the right pointer left
            if (nums[i] + nums[j] > target) {
                j--;
            }
            // If the sum of the current pair is less than the target, move the left pointer right
            else if (nums[i] + nums[j] < target) {
                i++;
            }
            // If we found a pair that sums up to the target
            else {
                // Skip duplicate values for the left pointer (to avoid duplicate triplets)
                while (i < j && nums[i] == nums[i + 1]) {
                    i++;
                }
                // Skip duplicate values for the right pointer (to avoid duplicate triplets)
                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }

                // Add the found triplet to the result vector (with the current i and j values)
                result.push_back({-target, nums[i], nums[j]});

                // Move both pointers inward to find new potential pairs
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        // If the array has fewer than 3 numbers, it's impossible to find a triplet
        if (n < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());  // Sort the array to apply the two-pointer technique

        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first element to avoid processing the same triplet multiple times
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int n1 = nums[i];  // The first element of the triplet
            int target = -n1;  // We need to find a pair that sums up to the negative of the first element

            // Call the twoSum function to find pairs that sum up to 'target' (which is -n1)
            twoSum(nums, target, i + 1, n - 1);
        }

        return result;  // Return all unique triplets
    }
};

