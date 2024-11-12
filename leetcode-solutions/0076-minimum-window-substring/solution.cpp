class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> mpp;
        for (char c : t) {
            mpp[c]++;
        }

        int left = 0, right = 0, count = t.size();
        int minLength = INT_MAX, sIndex = 0;

        while (right < s.size()) {
            if (mpp[s[right]] > 0) {
                count--;
            }
            mpp[s[right]]--;

            right++;
            while (count == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    sIndex = left;
                }

                mpp[s[left]]++;
                if (mpp[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(sIndex, minLength);
    }
};
