class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) 
    {
        int longestPush = events[0][1];
        int index = events[0][0];
        for(int i=1;i<events.size();i++)
        {
            int timeTaken = events[i][1]- events[i-1][1];
            if ( (timeTaken==longestPush && events[i][0]<index) || (timeTaken >longestPush) )
            {
                longestPush = timeTaken;
                index = events[i][0];
            }
        }
        return index;
        
    }
};
