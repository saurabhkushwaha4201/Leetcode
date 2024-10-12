class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
{
    stack<int> st; // Stack to keep track of asteroids

    for (int i = 0; i < asteroids.size(); i++) {
        if (asteroids[i] > 0) {
            // Push positive asteroids onto the stack
            st.push(asteroids[i]);
        } else {
            // Handle collision for negative asteroids
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                // Pop smaller positive asteroids
                st.pop();
            }
            if (!st.empty() && st.top() == abs(asteroids[i])) {
                // Both asteroids destroy each other
                st.pop();
            } else if (st.empty() || st.top() < 0) {
                // Push the negative asteroid if no collision or stack is empty
                st.push(asteroids[i]);
            }
        }
    }

    // Prepare the result vector from the stack
    vector<int> ans(st.size());
    for (int i = ans.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}
};
