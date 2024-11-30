class Solution {
public:
    int maxDepth(string s) 
    {
        int count=0;
        int maxi = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            count++;
            else if(s[i]==')')
            count--;
            else
            continue;

            maxi=max(maxi,count);
        }
        return maxi;
        
    }
};
