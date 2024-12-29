class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        int score = 0;
        vector<int>temp;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="C")
            {
                temp.pop_back();
            }
            else if (operations[i]=="D")
            {
                temp.push_back(2*temp.back());
            }
            else if(operations[i]=="+")
            {
                int num1= temp.back();
                temp.pop_back();
                int num2= temp.back();
                temp.push_back(num1);
                temp.push_back(num1+num2);
            }
            else
            temp.push_back(stoi(operations[i]));
        }
        return accumulate(temp.begin(),temp.end(),0);
        
    }
};
