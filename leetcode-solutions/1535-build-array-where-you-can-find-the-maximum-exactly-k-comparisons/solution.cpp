class Solution {
public:
    int dp[51][51][101];
    int MOD = 1e9 + 7;

    int solve(int index, int searchCost, int maxSoFar,int n, int m, int k)
    {
        if(index==n)
        {
            return (searchCost==k) ? 1 : 0;
        }
        if(dp[index][searchCost][maxSoFar]!=-1)
        {
            return dp[index][searchCost][maxSoFar];
        }
        int result = 0;
        for(int i = 1;i<=m;i++)
        {
            if(i>maxSoFar)
            {
                result = (result + solve(index +1 , searchCost +1,i,n,m,k)) % MOD;
            }
            else
            {
                result = (result + solve(index+1,searchCost,maxSoFar,n,m,k)) % MOD;
            }
        }
        return dp[index][searchCost][maxSoFar] =  result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,m,k);
    }
};
