class Solution {
public:
    bool validAnagram(string s,string t)
    {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t; 
        vector<int>freq1(26,0),freq2(26,0);
        for(int i = 0;i<s.length();i++){
            freq1[s[i]-'a']++;
        }

        for(int i = 0;i<t.length();i++){
            freq2[t[i]-'a']++;
        }

        for(int i = 0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) 
    {
        vector<string> uniqueWords;
        uniqueWords.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (validAnagram(words[i-1], words[i]))
                continue;
            else
                uniqueWords.push_back(words[i]);
        }
        return uniqueWords;
        
    }
};
