class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n ,-1); // Initialize result vector with -1
        stack<int> s;                        // Stack to keep track of indices

        for (int i = 2*n-1;i>=0; i--) 
        {
            while(!s.empty()&& s.top()<=nums[i%n])
            {
                s.pop();
            }
            if(i<n)
            {
                result[i]=s.empty()? -1: s.top();
            }
            s.push(nums[i%n]);
            
        }

        return result; // Return the result vector
    }
};
