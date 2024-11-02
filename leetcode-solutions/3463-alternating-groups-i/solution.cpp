class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) 
    {
        int alternatingGroupCount = 0;
        int n = colors.size();

        if (n < 3) return 0; // Not enough tiles to form a group

        // Check for alternating groups in a circular manner
        for (int i = 0; i < n; ++i) {
            // Use modulo to wrap around for circular indexing
            int left = colors[i];
            int middle = colors[(i + 1) % n];
            int right = colors[(i + 2) % n];

            // Check if it forms an alternating group
            if (left != middle && middle != right) {
                alternatingGroupCount++;
            }
        }

        return alternatingGroupCount;
        
    }
};
