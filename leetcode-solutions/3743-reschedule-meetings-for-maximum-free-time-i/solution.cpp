class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeTime;
        
 
        freeTime.push_back(startTime[0]);
        for(int i =1 ;i<startTime.size();i++)
        {
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }

        freeTime.push_back(eventTime - endTime[endTime.size()-1]);
        int n = freeTime.size();
        int  i = 0;
        int j = 0;
        int maxTime = 0;
        int sum = 0;
        while(i<n)
        {
            sum += freeTime[i];

            if(j <n &&i-j+1 > k+1)
            {
                sum -= freeTime[j];
                j++;
            }

            maxTime = max(maxTime,sum);
            i++;
        }
        return maxTime;
    }
};
