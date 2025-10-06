class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int Xor = 0;
        int count_0 = 0;
        int n  = nums.size();
        for(int i = 0;i<n;i++){
            Xor ^= nums[i];
            if(nums[i]==0){
                count_0++;
            }
        }
        if(count_0==n){
            return 0;
        }
        if(Xor==0){
            return n-1;
        }
        else return n;
    }
};
