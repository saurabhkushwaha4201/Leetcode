class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
    for (int num : nums) {
        sum += num;
    }
    int rem = sum % k;
    return rem;
    }
};
