class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        unordered_set<int>st(nums.begin(),nums.end());
        int distinctElements = st.size();

        int count=0;
        int right = 0;
        int left=0;
        unordered_map<int,int>mpp;
        while(right<nums.size())
        {
            mpp[nums[right]]++;
            while(mpp.size()==distinctElements)
            {
                count += nums.size()-right;
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)
                mpp.erase(nums[left]);
                left++;
            }
            right++;
        }
        return count;
    }
};
