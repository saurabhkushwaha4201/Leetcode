#include <vector>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        int n = arr.size();
        std::vector<int> prefixXOR(n);
        
        // Build the prefix XOR array
        prefixXOR[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }
        
        std::vector<int> ans;
        // Process each query
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            if (left == 0) {
                ans.push_back(prefixXOR[right]);
            } else {
                ans.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
            }
        }
        
        return ans;
    }
};

