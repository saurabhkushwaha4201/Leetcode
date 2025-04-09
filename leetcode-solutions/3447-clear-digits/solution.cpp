class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<char>st;
        string ans = "";
        for(int i =0;i<n;i++)
        {
            if(isdigit(s[i]) && !st.empty())
            {
                ans.pop_back();
                st.pop();
                
            }
            else 
            {
                st.push(s[i]);
                ans+=s[i];
            }
        }
        return ans;
    }
};
