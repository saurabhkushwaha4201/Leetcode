class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        // m and n are the dimensions of the matrix mat (rows and columns respectively)
        int m = mat.size(); // number of rows
        int n = mat[0].size(); // number of columns
        
        // Create a hashmap to store the index of each element in arr
        unordered_map<int, int> mpp;
        for(int i = 0; i < arr.size(); i++) {
            // Store the index of each element in arr for quick lookup
            mpp[arr[i]] = i;
        }

        // Initialize minIndex to the maximum possible value
        // This will store the index of the first complete row or column
        int minIndex = INT_MAX;

        // Check for the first complete row
        for(int row = 0; row < m; row++) {
            int lastIndex = INT_MIN; // To keep track of the last index of an element in arr for this row

            // Loop through each column in the row
            for(int col = 0; col < n; col++) {
                int val = mat[row][col]; // Get the value in the matrix
                int index = mpp[val]; // Get the index of this value from the hashmap

                // Update lastIndex to be the maximum index encountered in this row
                lastIndex = max(lastIndex, index);
            }

            // Update minIndex to be the minimum of its current value and the lastIndex for this row
            minIndex = min(minIndex, lastIndex);
        }

        // Check for the first complete column
        for(int col = 0; col < n; col++) {
            int lastIndex = INT_MIN; // To keep track of the last index of an element in arr for this column

            // Loop through each row in the column
            for(int row = 0; row < m; row++) {
                int val = mat[row][col]; // Get the value in the matrix
                int index = mpp[val]; // Get the index of this value from the hashmap

                // Update lastIndex to be the maximum index encountered in this column
                lastIndex = max(lastIndex, index);
            }

            // Update minIndex to be the minimum of its current value and the lastIndex for this column
            minIndex = min(minIndex, lastIndex);
        }

        // Return the final value of minIndex, which is the index of the first element
        // that completes a row or a column in the matrix
        return minIndex;
    }
};

