class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n*(n+1)/2;
        int k = (n/m);
        int num2 = k*(k+1)*m/2;
        int num1 = sum - num2;
        return num1-num2;
    }
};
