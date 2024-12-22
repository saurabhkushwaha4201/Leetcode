class Solution {
public:
    int minimumOperations(vector<int>& nums) 
{
    int operations = 0;
    
    while (true) {
       
        unordered_map<int, int>mpp;
        for (int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
        }
        
        
        bool allDistinct = true;
        for (auto& entry : mpp) {
            if (entry.second > 1) {
                allDistinct = false;
                break;
            }
        }
        
        if (allDistinct) {
            break;  
        }
        
        
        for (int i = 0; i < 3 && !nums.empty(); ++i) {
            nums.erase(nums.begin());  // Remove the first element
        }
        
       
        operations++;
    }
    
    return operations;
}
};
