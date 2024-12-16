class Solution {
public:
    bool validAnagram(string s,string t)
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t; 
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
