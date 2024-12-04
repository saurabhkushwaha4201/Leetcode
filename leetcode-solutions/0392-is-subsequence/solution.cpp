class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(s.length()>t.length())
        return false;
        int n1 = s.length();
        int n2 = t.length();
        int i=0;
        int j=0;
        while(i<n1 && j<n2)
        {
            if(t[j]==s[i])
            {
                i++;
            }
            j++;
        }
        if(i==n1)
        return true;
        return false;

    }
};
