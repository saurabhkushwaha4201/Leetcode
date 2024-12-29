class Solution {
public:
    string removeOuterParentheses(string& s) {
        stack<char> st;
        int index = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                if (!st.empty()) {
                    s[index++] = s[i];  // Not the outermost '(' so copy it
                }
                st.push(s[i]);  // Push '(' onto stack
            } else {
                st.pop();  // Pop '(' from stack
                if (!st.empty()) {
                    s[index++] = s[i];  // Not the outermost ')' so copy it
                }
            }
        }
        
        s.resize(index);  // Shrink the string to the correct size
        return s;
    }
};

