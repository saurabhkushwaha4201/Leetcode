class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<int>prev(len2+1,0),curr(len2+1,0);

        for(int i = 1;i<=len1;i++)
        {
            for(int j = 1;j<=len2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else
                {
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[len2];
    }
};
