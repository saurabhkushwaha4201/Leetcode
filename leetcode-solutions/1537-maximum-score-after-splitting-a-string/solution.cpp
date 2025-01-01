class Solution {
public:
    int maxScore(string s) 
    {
        int prefixSum = 0;
        int zeroes = 0;
        int maxi = INT_MIN;
        for(int i= 0;i<s.length();i++)
        {
            if(s[i]=='1')
            prefixSum++;
        }
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='0')
            zeroes++;
            if(s[i]=='1')
            prefixSum--;
            maxi = max(maxi,zeroes+prefixSum);
        }
        return maxi;
    }
};
