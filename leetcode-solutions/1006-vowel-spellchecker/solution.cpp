class Solution {
public:
    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        unordered_set<string>exact(wordList.begin(),wordList.end());
        unordered_map<string,string>caseMapping,vowelMapping;

        for(int i = 0;i<wordList.size();i++)
        {
            string lower = toLower(wordList[i]);
            string devowel = deVowel(lower);

            if(!caseMapping.count(lower))
            caseMapping[lower] = wordList[i];
            if(!vowelMapping.count(devowel))
            vowelMapping[devowel] = wordList[i];
        }
        vector<string>result;
        for(string s:queries){
            if(exact.find(s)!=exact.end())
            {
                result.push_back(s);
            }
            else
            {
                string lower = toLower(s);
                string devowel = deVowel(lower);
                if(caseMapping.count(lower))
                result.push_back(caseMapping[lower]);
                else if(vowelMapping.count(devowel))
                result.push_back(vowelMapping[devowel]);
                else
                result.push_back("");
            }

            
        }
        return result;
    }
private:
    string toLower(string s)
    {
        for (char& ch : s)
            ch = tolower(ch);
        return s;
    }

    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return ch=='a' || ch=='e' || ch=='i' || ch=='o'||ch=='u';
    }
    string deVowel(string s)
    {
        for(char &ch:s)
        {
            if(isVowel(ch))
            ch = '*';
        }
        return s;
    }
};
