class Solution {
public:
    int dp[32][2][2];
    int solve(int index, int tight, int prev, string &s)
    {
        if(index==s.size())
        {
            return 1;
        }
        if(dp[index][tight][prev]!=-1)
        {
            return dp[index][tight][prev];
        }

        int limit = tight ? s[index] -'0' : 1;
        int ans = 0;
        for(int digit = 0;digit<=limit;digit++)
        {
            int newTight = tight && (digit==limit);
            if((digit && prev) ==0)
            ans += solve(index+1,newTight,digit,s);
        }

        return dp[index][tight][prev] = ans;
    }
    string toBinary(int n) 
    {
        if (n == 0) return "0";
        string res = "";
        while (n > 0) {
            res = char('0' + (n % 2)) + res;
            n /= 2;
        }
        return res;
    }
    int findIntegers(int n) {
        string binary = toBinary(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,0,binary);
    }
};
