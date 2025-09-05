class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int i = 1;
        while(true){
            long long  val = num1 - (long long)i*num2;
            if(val<0)
            return -1;
            if(__builtin_popcountll(val)<=i && val>=i)
            return i;
            i++;
        }
        return -1;
    }
};
