class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char,int>mpp;
        int n= s.length();
        int start=0;
        int end=0;
        int maxLength=0;
        int len=0;
        while(end<n)
        {
            if(mpp.find(s[end])!=mpp.end() && mpp[s[end]]>=start)
            {
                start = mpp[s[end]] + 1;
            }
            len = end-start + 1;
            maxLength= max(maxLength,len);
            mpp[s[end]]=end;
            end++;
        }
        return maxLength;
        
    }
};
