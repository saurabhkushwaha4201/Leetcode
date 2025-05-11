class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mpp;
        for(char ch : s)
            mpp[ch]++;

        if(mpp.size()<=k)
            return 0;

        vector<int>freq;
        for(auto it:mpp)
            {
                freq.push_back(it.second);
            }

        sort(freq.begin(),freq.end());

        int deletions = 0;
    int distinctChars = freq.size();

 
    for (int i = 0; i < freq.size() && distinctChars > k; ++i) {
        deletions += freq[i];
        distinctChars--;
    }

    return deletions;
    }
};
