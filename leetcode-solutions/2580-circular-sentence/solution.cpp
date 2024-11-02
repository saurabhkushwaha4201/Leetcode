class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
        int n=sentence.length();
        bool flag=true;
        if(sentence[0]!=sentence[n-1])
        {
            flag=false;
            return flag;
        }
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                if(sentence[i-1]!=sentence[i+1])
                {
                    flag=false;
                    return flag;
                }
            }
        }
        return flag;
    }
};
