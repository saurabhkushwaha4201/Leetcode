class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int maxScore = INT_MIN;
        int max_i = values[0];
        for(int i=1;i<values.size();i++ )
        {
            int max_j = values[i] -i;
            maxScore = max(maxScore, max_i + max_j);

            max_i = max(max_i,values[i]+i);
        }
        return maxScore;
        
    }
};
