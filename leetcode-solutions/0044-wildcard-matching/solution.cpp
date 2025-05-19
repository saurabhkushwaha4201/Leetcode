class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        // dp[i][j] = does p[0..i-1] match s[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty pattern matches empty string
        dp[0][0] = true;

        // Initialize first column (pattern matches empty string)
        for (int i = 1; i <= m; ++i) {
            if (p[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
            else
                break;  // Once a non-* is encountered, rest can't match empty string
        }

        // Fill the table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j]   // '*' matches empty
                             || dp[i][j - 1]; // '*' matches one more char
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};

