class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        // Find the position of the character 'ch' in the string 'word'
        size_t pos = word.find(ch);

        // If the character is not found, return the word as is
        if (pos == string::npos) {
            return word;
        }
        
        // Reverse the substring from the start to the found position
        // Use substring to get the prefix, then reverse it
        string prefix = word.substr(0, pos + 1); // substring including the character ch
        reverse(prefix.begin(), prefix.end());  // Reverse the prefix

        // Concatenate the reversed prefix with the remainder of the string
        return prefix + word.substr(pos + 1);   // Rest of the string after the character
    }
};

