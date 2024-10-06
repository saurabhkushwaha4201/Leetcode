class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
        if(sentence1.length()>sentence2.length())
        {
            return (areSentencesSimilar(sentence2,sentence1));
        }
        stringstream ssentence1(sentence1), ssentence2(sentence2);
        string word;
        vector<string> smallerWords, largerWords;
        while (ssentence1 >> word) smallerWords.push_back(word);
        while (ssentence2 >> word) largerWords.push_back(word);
        // string smallerWords[]=sentence1.split(" ");
        // string largerWords[]=sentence2.split(" ");
        int start=0;
        int end1=smallerWords.size()-1;
        int end2=largerWords.size()-1;
        // for prefix words
        while(start<=end1 && smallerWords[start]==largerWords[start])
        {
            start++;
        }
        // for suffix words
        while(start<=end1 && smallerWords[end1]==largerWords[end2])
        {
            end1--;
            end2--;
        }
        return (start>end1);
        
    }
};
