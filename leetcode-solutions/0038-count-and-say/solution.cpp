class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1)
        {
            return "1";
        }

        string ans = "1";

        n -=1;
        while(n--)
        {
            int length = ans.length();
            string temp = "";
            int i = 0;
            while(i<length)
            {
                char say = ans[i];
                int count = 1;
                i++;
                while(i<length && ans[i]==say)
                {
                    i++;
                    count++;
                }
                temp.push_back(count+'0');
                temp.push_back(say);
            }
            ans = temp;

        }
        return ans;
        
    }
};
