class Solution {
public:
    int dp[10][2][6][6][20][2];
    int solve(string &s,int index, int tight, int oddCount, int evenCount, int remainder, int validNum, int k)
    {
        if(index==s.length())
        {
            return (oddCount == evenCount) && (remainder == 0);
        }
        if(oddCount > 5 || evenCount > 5)
        return 0;
        if(dp[index][tight][oddCount][evenCount][remainder][validNum]!=-1)
        {
            return dp[index][tight][oddCount][evenCount][remainder][validNum];
        }

        int limit = tight ? s[index] - '0' : 9;
        int ans = 0;
        for(int digit = 0; digit<=limit ; digit++)
        {
            int newTight = tight && (digit==limit);
            if(validNum==false && digit==0)
            {
                ans += solve(s, index+1,newTight, oddCount, evenCount, remainder, false, k);
            }
            else if(digit%2==0)
            {
                ans += solve(s, index+1,newTight, oddCount, evenCount+1, (remainder*10 + digit) % k, true, k);
            }
            else
            {
                ans += solve(s, index+1, newTight, oddCount+1, evenCount, (remainder*10 + digit) % k , true, k);
            }
        }
        return dp[index][tight][oddCount][evenCount][remainder][validNum] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string l  = to_string(low-1);
        memset(dp,-1,sizeof(dp));
        int countNum1 = solve(l,0,true,0,0,0,false,k);

        string h = to_string(high);
        memset(dp,-1,sizeof(dp));
        int countNum2 = solve(h,0,true,0,0,0,false,k);

        return countNum2 - countNum1;
    }
};
