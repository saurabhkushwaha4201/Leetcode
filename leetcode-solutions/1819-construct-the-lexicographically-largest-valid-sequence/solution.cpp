class Solution {
public:
    bool solve(int i, int n, vector<int>& result, vector<bool>& used) {
        if (i >= result.size()) {
            return true;
        }

        // Skip already filled positions
        if (result[i] != -1) {
            return solve(i + 1, n, result, used);
        }

        // Try placing each number from n to 1
        for (int num = n; num >= 1; num--) {
            // Skip if the number has already been used
            if (used[num]) continue;

            // Try placing 'num' at index i
            result[i] = num;
            used[num] = true;

            if (num == 1) {
                // For num == 1, we can just proceed to the next position
                if (solve(i + 1, n, result, used)) {
                    return true;
                }
            } else {
                // For other numbers, try placing them at index i and index i + num
                int j = i + num;

                if (j < result.size() && result[j] == -1) {
                    result[j] = num;
                    if (solve(i + 1, n, result, used)) {
                        return true;
                    }
                    result[j] = -1;  // backtrack
                }
            }

            // Backtrack if placing num doesn't lead to a solution
            result[i] = -1;
            used[num] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n-1, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, result, used);
        return result;
    }
};

