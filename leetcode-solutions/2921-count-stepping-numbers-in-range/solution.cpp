class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[101][2][101][2];
    int solve(string s, int index, int tight, int prev, int validNum)
    {
        if(index==s.length())
        {
            return validNum==true;
        }

         if (dp[index][tight][prev][validNum] != -1) {
            return dp[index][tight][prev][validNum];
        }
        int limit = tight ? s[index] - '0' : 9;
        int totalCount = 0;
        for(int digit = 0;digit<=limit;digit++)
        {
            int newTight = tight && (digit==limit);
            if(validNum==false && (digit==0))
            {
                totalCount  = (totalCount + solve(s,index+1,newTight,prev,false)) % MOD;
            }
            else if(validNum == false && digit>0)
            {
                totalCount = (totalCount + solve(s,index+1,newTight,digit,true)) % MOD;
            }
            else if(abs(digit-prev)==1)
            {
                totalCount = (totalCount + solve(s,index+1,newTight,digit,true)) % MOD;
            }
        }
        return dp[index][tight][prev][validNum] = totalCount;
    }

    int countSteppingNumbers(string low, string high) {

        memset(dp,-1,sizeof(dp));
        int countNum1 = solve(low,0,true,0,false);
        int i = 1;
        while(i<low.size())
        {
            if(abs((low[i-1]-'0') - (low[i]-'0')) !=1)
            break;

            i++;
        }
        if(i==low.size())
        countNum1--;
        memset(dp,-1,sizeof(dp));
        int countNum2 = solve(high,0,true,0,false);

        return (countNum2 - countNum1 + MOD) % MOD;
    }
};
