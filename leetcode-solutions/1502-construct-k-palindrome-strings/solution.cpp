class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if(s.length()<k)
        return false;

        map<char,int>mpp;
        for(char ch:s)
        {
            mpp[ch]++;
        }
        int count =0;
        for (auto it = mpp.begin(); it != mpp.end(); ++it)
        {
            if((it->second) %2!=0)
            {
                count++;
            }
        }
        if(count>k)
        return false;

        return true;

        
    }
};
