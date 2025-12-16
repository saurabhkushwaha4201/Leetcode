class Solution {
public:
    vector<vector<long long>> getSubsetSumsBitmask(vector<int>& arr) {
        int m = arr.size();
        vector<vector<long long>> res(m + 1);

        for (int mask = 0; mask < (1 << m); mask++) {
            int count = 0;
            long long sum = 0;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    count++;
                    sum += arr[i];
                }
            }
            res[count].push_back(sum);
        }
        return res;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto leftSums  = getSubsetSumsBitmask(left);
        auto rightSums = getSubsetSumsBitmask(right);

        for (int k = 0; k <= n; k++) {
            sort(rightSums[k].begin(), rightSums[k].end());
        }

        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        long long ans = LLONG_MAX;

        for (int k = 0; k <= n; k++) {
            auto& L = leftSums[k];
            auto& R = rightSums[n - k];

            for (long long leftSum : L) {
                long long target = totalSum / 2 - leftSum;
                auto it = lower_bound(R.begin(), R.end(), target);

                if (it != R.end())
                    ans = min(ans, llabs(totalSum - 2 * (leftSum + *it)));
                if (it != R.begin()) {
                    --it;
                    ans = min(ans, llabs(totalSum - 2 * (leftSum + *it)));
                }
            }
        }
        return ans;
    }
};

