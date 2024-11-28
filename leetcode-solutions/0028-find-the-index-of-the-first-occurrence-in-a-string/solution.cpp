class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int length1 = haystack.length();
        int length2=needle.length();
        if(length2>length1)
        return -1;
        for(int i=0;i<length1;i++)
        {
            string str = haystack.substr(i,length2);
            if(str==needle)
            return i;
        }
        return -1;
        
    }
};
