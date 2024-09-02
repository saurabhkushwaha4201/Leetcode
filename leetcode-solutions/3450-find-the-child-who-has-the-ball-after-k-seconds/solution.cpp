class Solution {
public:
    int numberOfChild(int n, int k) 
    {
        int complete_round= k/(n-1);
        int extra_time=k%(n-1);
        if(complete_round%2==0)
        {
            return extra_time;
        }
        else
        {
            return n - 1-extra_time;
        }

        
    }
};
