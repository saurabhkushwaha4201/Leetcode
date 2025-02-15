class Solution {
public:
    vector<int> size;  // To store the size of each component
    vector<int> parent;  // To store the parent of each component

    // Find function with path compression
    int find(int i) {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i]);  // Path compression for optimization
    }

    // Union by size function to connect two components
    void unionBysize(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)  // Already in the same component
            return;

        // Union by size: attach the smaller tree to the root of the larger tree
        if (size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        size.resize(n, 1);

        // Initialize each account as its own parent (each account is a separate component initially)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Mapping email addresses to account indices
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;  // Assign account index to this email
                } else {
                    // Union the current account with the previously found account for this email
                    unionBysize(i, mpp[mail]);
                }
            }
        }

        // To store merged emails for each component
        unordered_map<int, vector<string>> components;

        // Add the emails into the respective component (root of the connected components)
        for (auto& it : mpp) {
            int root = find(it.second);  // Find the root of the account for the current email
            components[root].push_back(it.first);  // Add the email to the corresponding component
        }

        // Prepare the final answer
        vector<vector<string>> ans;
        for (auto& it : components) {
            vector<string> temp;
            int root = it.first;
            temp.push_back(accounts[root][0]);  // The account name (the first element of each account)

            // Sort emails within the same component
            sort(it.second.begin(), it.second.end());

            // Add all emails to the result vector
            temp.insert(temp.end(), it.second.begin(), it.second.end());
            ans.push_back(temp);
        }

        return ans;
    }
};

