class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        // Create a max-heap from the input nums array.
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
        
        // Perform the operation for 'k' iterations.
        while (k--) {
            int maxVal = pq.top(); // Get the largest value.
            pq.pop();              // Remove it from the heap.
            score += maxVal;       // Add to the score.
            
            // Reduce the value and push back into the heap.
            // Use (maxVal + 2) / 3 for correct rounding of division by 3.
            pq.push((maxVal + 2) / 3);
        }
        
        return score;
    }
};

