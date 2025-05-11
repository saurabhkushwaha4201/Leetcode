class Solution {
public:
    bool canPartitionGrid(const vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return false;

    int m = grid.size();
    int n = grid[0].size();
    long long total = 0;

    // Precompute row and column sums in one pass
    vector<long long> rowSums(m, 0LL), colSums(n, 0LL);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            long long v = grid[i][j];
            total  += v;
            rowSums[i] += v;
            colSums[j] += v;
        }
    }

    // If total is odd, you can't split into two equal halves
    if (total % 2 != 0) return false;
    long long target = total / 2;

    // Check horizontal cuts in O(m)
    long long acc = 0;
    for (int i = 0; i < m - 1; ++i) {
        acc += rowSums[i];
        if (acc == target) return true;
    }

    // Check vertical cuts in O(n)
    acc = 0;
    for (int j = 0; j < n - 1; ++j) {
        acc += colSums[j];
        if (acc == target) return true;
    }

    return false;
}



};
