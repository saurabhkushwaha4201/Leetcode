class Solution {
public:
    const int MOD  = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        int j = n-1;
        
        sort(nums.begin(),nums.end());
        vector<int>power(n);
        power[0] = 1;
        for(int i = 1;i<n;i++)
        {
            power[i] = (power[i-1] * 2) % MOD;
        }
        while(i<=j)
        {
            int smallest = nums[i];
            int largest = nums[j];
            if(smallest + largest<=target)
            {
                count = (count +  power[j-i]) % MOD;
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;
    }
};
