class Solution {
public:
    int divisorSubstrings(int num, int k) 
    {
        string str = to_string(num);
        int count=0;
        
        for(int i=0;i<=str.length()-k;i++)
        {
            string temp = str.substr(i,k);
            if(stoi(temp)!=0 && num % stoi(temp) == 0)
            {
                count++;
            }
        }
        return count;
        
    }
};
