class Solution {
public:
    int timeToMinutes(const string& timeStr) 
    {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3));
    
    // Convert to total minutes
    return hours * 60 + minutes;
    }

    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int> minutes;
        for(auto str:timePoints)
        {
            minutes.push_back(timeToMinutes(str));
        }
        sort(minutes.begin(),minutes.end());
        int minDiff = INT_MAX;
        
        for (int i = 0; i < minutes.size()-1; ++i) 
        {
            minDiff = min(minDiff, abs(minutes[i + 1] - minutes[i]));
        }
        minDiff = min(minDiff, (1440 - minutes.back() + minutes.front()));
        return minDiff;
        
    }
};
