class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n  = nums.size();
        int left = 0;
        int right = 0;
        long long count = 0;
        map<int,int>mp;
        while(right<n)
        {
            mp[nums[right]]++;
            // prev(mp.end())->first:  gives max key
            // mp.begin()->first: gives min key
            while(prev(mp.end())->first - mp.begin()->first > 2)
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                mp.erase(nums[left]);
                left++;
            }
            
            count += (right-left+1);
            right++;
        }
        return count;
    }
};
