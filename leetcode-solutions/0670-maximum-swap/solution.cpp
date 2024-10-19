class Solution {
public:
    int maximumSwap(int num) 
    {
        string str=to_string(num);
        int maxIndex = -1;
        int index1= -1;
        int index2= -1;
        int n=str.length();
        for(int i=n-1;i>=0;i--)
        {
            if(maxIndex == -1 || str[i]>str[maxIndex])
            {
                maxIndex=i;
            }
            else if(str[i]<str[maxIndex])
            {
                index1=i;
                index2=maxIndex;
            }

        }
        if(index1 != -1 && index2 != -1)
        {
            swap(str[index1],str[index2]);
        }
        return stoi(str);
    }
};
