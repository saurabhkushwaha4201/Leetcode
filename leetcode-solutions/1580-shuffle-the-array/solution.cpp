class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int>answer;
        int i=0;
        int j=n;
        while(i<n&&j<nums.size())
        {
            answer.push_back(nums[i]);
            answer.push_back(nums[j]);
            i++;
            j++;
        }
        return answer;


        
    }
};
