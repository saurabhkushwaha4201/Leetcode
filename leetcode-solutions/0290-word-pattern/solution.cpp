class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        stringstream ss(s);
        string word;
        unordered_map<char,string>mpp1;
        unordered_map<string,char>mpp2;
        vector<string>words;
        while(ss>>word)
        {
            words.push_back(word);
        }
        if (words.size() != pattern.length()) {
            return false;
        }
        for(int i=0;i<pattern.length();i++)
        {
           // pattern ka s se mapping
            // agr phle se mapping h to
            if(mpp1.count(pattern[i]))
            {
                if(mpp1[pattern[i]]!=words[i])
                return false;
            }
            // mapping kro  pattern ko words se
            else
            {
                mpp1[pattern[i]]=words[i];
            }

            // s ka pattern se mapping
            if(mpp2.count(words[i]))
            {
                if(mpp2[words[i]]!=pattern[i])
                return false;
            }
            else
            {
                mpp2[words[i]]=pattern[i];
            }

        }
        return true;
    }
};
