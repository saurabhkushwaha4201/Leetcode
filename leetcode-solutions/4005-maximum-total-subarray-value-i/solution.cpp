class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long result = 0;
        long long maxi = *max_element(nums.begin(),nums.end());
        long long mini = *min_element(nums.begin(),nums.end());
        result = (maxi-mini)*k;
        return result;
    }
};
