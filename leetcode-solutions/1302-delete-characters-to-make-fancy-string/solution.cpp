class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            // Check bounds before accessing i+1 and i+2
            if (i < s.size() - 2 && s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
                continue;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
