class Solution {
public:
    void solve(int currNum, int n, vector<int>&result)
    {
        if(currNum>n)
        return ;

        result.push_back(currNum);
        for(int append = 0;append<=9;append++)
        {
            int newNum = (currNum * 10) + append;
            if(newNum>n)
            return;
            solve(newNum,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int i = 1;i<=9;i++)
        {
            solve(i,n,result);
        }
        return result;
    }
};
