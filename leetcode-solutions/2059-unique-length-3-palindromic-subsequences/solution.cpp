class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int n=s.length();
        vector<pair<int,int>>indices(26,{-1,-1});

        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            int idx = ch - 'a';

            if(indices[idx].first==-1)
            {
                indices[idx].first = i;
            }
            indices[idx].second= i;
        }
        
        int ans = 0;
        for(int i =0;i<26;i++)
        {
            int leftIndex = indices[i].first;
            int rightIndex = indices[i].second;

            if(leftIndex ==-1)
            continue;

            unordered_set<char>st;
            for(int middle = leftIndex + 1; middle<= rightIndex - 1;middle++)
            {
                st.insert(s[middle]);
            }
            ans += st.size();
        }
        return ans;
    }
};
