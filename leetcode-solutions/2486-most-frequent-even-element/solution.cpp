class Solution {
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int mostFreq = 0;
        int result = INT_MAX;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                mp[nums[i]]++;

                if(mp[nums[i]]>mostFreq ||(mp[nums[i]]==mostFreq&& nums[i]<result))
                {
                    result = nums[i];
                    mostFreq = mp[nums[i]];
                }
            }
        }

        if(mostFreq == 0)
        return -1;

        return result;
        
    }
};
