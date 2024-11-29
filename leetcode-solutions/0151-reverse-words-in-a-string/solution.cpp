class Solution {
public:
    string reverseWords(string s) 
    {
        string reversed;
        int n = s.length();
        stringstream ss(s);
        vector<string>ans;
        while(ss>>reversed)
        {
            ans.push_back(reversed);
        }
        int i=ans.size()-1;
        string result ="";
        while(i>=0)
        {
            result += ans[i];
            if (i > 0) {
                result += " "; 
            }
            i--;
        }
        return result;

    }
};
