class Solution {
public:
    string findValidPair(string s) 
{
    map<char,int>mpp;
    for(auto ch : s)
        {
            mpp[ch]++;
        }
    string result = "";
    for(int i =0;i<s.length()-1;i++)
        {
            char first = s[i];
            char second  = s[i+1];
            if(first!=second && mpp[first]==(first-'0') && mpp[second]==(second-'0'))
            {
                result += first;
                result += second;
                return result;
            }
        }
        return "";
    }
};
