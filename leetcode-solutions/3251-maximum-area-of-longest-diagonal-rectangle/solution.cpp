class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
       double maxDiagonal = 0;
    int maxArea = 0;
    
    for (auto& dim : dimensions) {
        int length = dim[0];
        int width = dim[1];
        
        // Calculate the diagonal using Pythagoras' theorem
        double diagonal = sqrt(length * length + width * width);
        int area = length * width;
        
        // Check if this rectangle has a longer diagonal
        if (diagonal > maxDiagonal) {
            maxDiagonal = diagonal;
            maxArea = area;
        }
        // If diagonals are the same, take the rectangle with the larger area
        else if (diagonal == maxDiagonal) {
            maxArea = max(maxArea, area);
        }
    }
    
    return maxArea;
        
    }
};
