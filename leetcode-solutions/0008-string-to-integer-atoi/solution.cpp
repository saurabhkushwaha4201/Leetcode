class Solution {
public:
    int myAtoi(string s) 
    {
        long long result =0;
        bool isNegative=false;
        int i=0;
        // skip whitespaces
        while(i<s.length()&& s[i]==' ')
        {
            i++;
        }
        // determine sign
        if(i<s.size()&& (s[i]=='-' || s[i]=='+') )
        {
            if(s[i]=='-')
            isNegative=true;
            i++;
        }
        // slip leading zeroes
        while(i<s.size()&& s[i]=='0')
        {
            i++;
        }
        // find result from integer
        while(i<s.size()&& isdigit(s[i]))
        {
            result=result*10 + (s[i]-'0');

            // Handle overflow
            if(result>INT_MAX)
            {
                return isNegative ? INT_MIN : INT_MAX;
            }
            i++;
        }

        // apply sign
        return isNegative? -result : result;
        
    }
};
