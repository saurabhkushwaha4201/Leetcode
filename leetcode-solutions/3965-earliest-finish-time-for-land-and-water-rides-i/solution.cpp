class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int shortestTime = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int landStart = max(landStartTime[i], 0);
                int landEnd = landStart + landDuration[i];
                int waterStartAfterLand = max(waterStartTime[j], landEnd);
                int finishTime1 = waterStartAfterLand + waterDuration[j];
                shortestTime = min(shortestTime, finishTime1);

                int waterStart = max(waterStartTime[j], 0);
                int waterEnd = waterStart + waterDuration[j];
                int landStartAfterWater = max(landStartTime[i], waterEnd);
                int finishTime2 = landStartAfterWater + landDuration[i];
                shortestTime = min(shortestTime, finishTime2);
            }
        }
        return shortestTime;
    }
};
