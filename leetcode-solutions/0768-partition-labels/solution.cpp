class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = i;
        }
        int end = 0, size = 0;
        vector<int> result;
        for(int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, mp[s[i]]);
            if(i == end) {
                result.push_back(size);
                size = 0;
            }
        }
        return result;
    }
};
