class Solution {
public:
    int count = 0;
    bool isPrefixAndSuffix(string str1 , string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();

        if(str1 == str2.substr(0,len1) && str1== str2.substr(len2-len1,len1))
        {
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(isPrefixAndSuffix(words[i],words[j]))
                {
                    count++;
                }
            }
            
        }
        return count;
    }
};
