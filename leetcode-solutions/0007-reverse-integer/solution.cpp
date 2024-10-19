
#include <bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
        int temp = abs(x);
        string str = to_string(temp);
        std::reverse(str.begin(), str.end());
        long long ans=0;
        if (x > 0)
            ans = stoll(str);
        else {
            ans = stoll(str);
            ans = -ans;
        }
        if(ans > INT_MAX || ans< INT_MIN)
        return 0;
        return ans;
    }
};
