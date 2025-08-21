class Solution {
public:
    int reverseBits(int n) {
        int result = 0;

        int totalBits = 32;
        while(totalBits--)
        {
            int bit = (n&1);
            result = (result<<1) | bit;
            n = n>>1;
        }
        return result;
    }
};
