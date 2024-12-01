class Solution {
public:
    int getLargestOutlier(vector<int>& nums) 
{
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    multiset<int> numSet(nums.begin(), nums.end());
    int largestOutlier = INT_MIN;

    for (int num : nums) 
    {
        int tempSum = totalSum - num;
        if (tempSum % 2 == 0) 
        {
           numSet.erase(numSet.find(num));
            int halfSum = tempSum/2;
            if(numSet.find(halfSum) !=numSet.end())
                {
                largestOutlier = max(num,largestOutlier);
                }
        }
        numSet.insert(num);
    }

    return largestOutlier;
        
    }
};
