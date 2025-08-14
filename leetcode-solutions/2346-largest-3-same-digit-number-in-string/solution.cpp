class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        int n = num.length();
        int maxi = -1;
        for(int i = 0;i<num.length();i++)
        {
            if(i+1<n && i+2<n && num[i]==num[i+1] && num[i+1]==num[i+2] && (num[i]-'0')>maxi)
            {
                maxi = num[i]-'0';
                result.clear();
                result.push_back(num[i]);
                result.push_back(num[i+1]);
                result.push_back(num[i+2]);
            }
        }
        return result;
    }
};
