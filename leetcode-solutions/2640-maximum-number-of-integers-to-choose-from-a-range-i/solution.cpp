class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        set<int>st;
        int sum=0;
        int count=0;
        for(int i=0;i<banned.size();i++)
        {
            if(banned[i]<=n)
            {
                st.insert(banned[i]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(st.find(i)==st.end() && sum +i <=maxSum)
            {
                sum+= i;
                count++;
            }
        }
        return count;
    }
};
