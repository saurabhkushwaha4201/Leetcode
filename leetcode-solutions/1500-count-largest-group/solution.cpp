class Solution {
public:
    int digitCount (int n)
    {
        int sum = 0;
        while(n)
        {
            int digit = n%10;
            sum += digit;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        int largestSize = INT_MIN;
        int count = 0;
        for(int i =1;i<=n;i++)
        {
            int digitSum = digitCount(i);
            mpp[digitSum]++;
            largestSize = max(largestSize,mpp[digitSum]);
        }
        for(auto it:mpp)
        {
            if(it.second==largestSize)
            count++;
        }
        return count;
    }
};
