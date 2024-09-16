class Solution {
public:
    bool palindrome(int start,int end,string s)
    {
        int flag=1;
        while(start<end)
        {
           
            if(s[start]!=s[end])
            {
                flag=0;
            }
            start++;
            end--;
        }
        return flag;

    }
    bool validPalindrome(string s) 
    {
        int start=0;
        int end=s.length()-1;
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            {
                return (palindrome(start+1,end,s)||(palindrome(start,end-1,s)));
            }
        }
        return true;


        
    }
};
