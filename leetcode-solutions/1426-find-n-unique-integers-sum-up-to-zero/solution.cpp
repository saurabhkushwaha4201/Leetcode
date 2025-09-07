class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int num = -n / 2;
        for (int i = 0; i < n;) {
            if (num == 0 && n % 2 == 0) {
                num++;
                continue;
            }
            result.push_back(num);
            num++;
            i++;
        }
        return result;
    }
};
