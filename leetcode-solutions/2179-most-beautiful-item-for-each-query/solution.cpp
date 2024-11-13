class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        std::sort(items.begin(), items.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        
        // Create a vector of pairs (query value, original index)
        std::vector<std::pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        // Sort queries by value
        std::sort(sortedQueries.begin(), sortedQueries.end());

        std::vector<int> ans(queries.size(), 0); // Result array initialized to 0
        int j = 0; // Pointer to traverse the items array
        int maxBeauty = 0; // Initialize maxBeauty to 0 for each query

        // Process each query in sorted order
        for (const auto& queryPair : sortedQueries) {
            int query = queryPair.first;
            int originalIndex = queryPair.second;

            // Update maxBeauty for this query
            while (j < items.size() && items[j][0] <= query) {
                maxBeauty = std::max(maxBeauty, items[j][1]);
                j++;
            }

            // Store the result at the original index
            ans[originalIndex] = maxBeauty;
        }

        return ans;
        
    }
};
