class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> output;

        // Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end());

        // Initialize the first interval as the current interval
        vector<int> currentInterval = intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            // If the current interval overlaps with the next interval
            if(currentInterval[1] >= intervals[i][0]){
                // Merge intervals by updating the end time of the current interval
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            }
            else{
                // Add the current interval to the output
                output.push_back(currentInterval);
                // Move to the next interval
                currentInterval = intervals[i];
            }
        }

        // Add the last interval to the output
        output.push_back(currentInterval);

        return output;      
    }
};

