class Solution {
public:
    int maxDifference(string s) 
{
    unordered_map<char,int>mpp;
    int maxOdd = INT_MIN;
    int minEven = INT_MAX;
    for(char ch : s)
        {
            mpp[ch]++;
            
        }
    for (const auto& pair : mpp) {
        if (pair.second % 2 == 0) {
            minEven = min(minEven, pair.second);
        } else {
            maxOdd = max(maxOdd, pair.second);
        }
    }
    if(maxOdd ==INT_MIN || minEven == INT_MAX)
        return -1;
        return (maxOdd - minEven);
    }
};
