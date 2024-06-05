class Solution {
public:
    string removeDuplicates(string s) 
    {
        //int len = s.length();
       // read:
        for (int i = 0; i < s.length();) 
        {
            if (i + 1 < s.length() && s[i] == s[i + 1]) 
            {
                s.erase(i, 2);
                i=0;
                //len = s.length(); 
                //goto read;
            } else {
                i++;
            }
        }
        return s;
    }
};
