class Solution {
public:
    int maximumLength(string s) 
    {
        map<pair<char,int>,int>count;
        for(int i=0;i<s.length();i++)
        {
            char character = s[i];
            int length=0;
            for(int j=i;j<s.length();j++)
            {
                if(character==s[j])
                {
                    length++;
                    count[{character,length}]++;
                }
                else
                break;
            }
        }
        int ans=0;
        for(auto i:count)
        {
            int len = i.first.second;
            if(i.second>=3 && len>ans)
            ans=len;
            
        }
        if(ans==0)
        return -1;
        return ans;
    }
};
