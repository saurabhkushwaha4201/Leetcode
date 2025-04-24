class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int count = 0;
        map<int,int>mpp;
        for(int right = 0;right<nums.size();right++)
        {
            mpp[nums[right]]++;
            while(mpp.size()==st.size())
            {
                count +=(n-right);
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)
                mpp.erase(nums[left]);
                left++;
            }
        }
        return count;
    }
};
