class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>answer;
        map<char,int>mpp1;
        for(char ch:p)
        {
            mpp1[ch]++;
        }
        map<char,int>mpp2;
        for(int i=0;i<p.length();i++)
        {
            mpp2[s[i]]++;
        }
        if(mpp1==mpp2)
        {
            answer.push_back(0);
        }
        for(int i=p.length();i<s.length();i++)
        {
            mpp2[s[i]]++;
            char left=s[i-p.length()];
            if(mpp2[left]==1)
            mpp2.erase(left);
            else
            mpp2[left]--;
            if(mpp1==mpp2)
            answer.push_back(i-p.length()+1);
        }
        return answer;
        
    }
};
