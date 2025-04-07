class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};

        auto pos1 = lower_bound(nums.begin(), nums.end(), target);
        if(pos1 == nums.end() || *pos1 != target)
            return {-1, -1};

        auto pos2 = upper_bound(nums.begin(), nums.end(), target);
        vector<int>result;
        result.push_back(pos1-nums.begin());
        result.push_back(pos2-nums.begin()-1);
        return result;
    }
};

