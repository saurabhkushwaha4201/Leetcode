class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        map<char, int> mpp; // Frequency map
        int maxFre = 0; // Maximum frequency of a character in the current window
        int maxLength = 0; // Maximum length of valid substring

        while (right < s.size()) {
            // Increment the count of the current character
            mpp[s[right]]++;

            // Update the maximum frequency found in the current window
            maxFre = max(maxFre, mpp[s[right]]);

            // If the number of changes required exceeds k, shrink the window from the left
            if ((right - left + 1) - maxFre > k) {
                mpp[s[left]]--; // Decrement the count of the left character
                left++; // Move the left pointer to the right
            }

            // Update the maximum length of valid substring
            maxLength = max(maxLength, right - left + 1);

            // Move the right pointer to expand the window
            right++;
        }

        return maxLength;
    }
};
