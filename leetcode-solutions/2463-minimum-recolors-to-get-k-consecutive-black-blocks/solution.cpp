class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int left = 0;
        int right = 0;
        int n = blocks.size();
        int white = 0;
        int result = INT_MAX;
        while(right<n)
        {
            if(blocks[right]=='W')
            {
                white++;
            }

            if(right-left+1 ==k)
            {
                result =min(result,white);
                if(blocks[left]=='W')
                {
                    white--;
                }
                
                left++;
            }
            right++;
        }
        return result;
    }
};
