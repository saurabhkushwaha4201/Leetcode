class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int n=chalk.size();
        long long int chalk_sum=0;
        for(int i=0; i<n;i++)
        {
            chalk_sum +=chalk[i];
        }
        int remaining_chalk=  k % chalk_sum;
        
        for(int i=0;i<n;i++)
        {
            if(remaining_chalk<chalk[i])
            {
                return i;
            }
           remaining_chalk =remaining_chalk - chalk[i];
           
        }
        return -1;
    }
};
