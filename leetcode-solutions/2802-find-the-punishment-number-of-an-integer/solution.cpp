class Solution {
public:
    bool check(int squa,int currSum, int num)
    {
        if(squa==0 )
        return currSum==num;

        return check(squa/10,currSum + squa % 10 ,num) ||
                check(squa/100, currSum + squa %100,num) ||
                check(squa/1000,currSum + squa %1000,num) ||
                check(squa/10000,currSum + squa % 10000,num);
        
    }
    int punishmentNumber(int n) 
    {
        int punish = 0;
        for(int i =1;i<=n;i++)
        {
            int sq = i * i;
            if(check(sq,0,i))
            {
                punish += sq;
            }
        }
        return punish;
        
    }
};
