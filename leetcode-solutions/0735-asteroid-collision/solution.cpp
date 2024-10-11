class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
{
    list<int> st;
    for (int i = 0; i < asteroids.size(); i++) {
        if (asteroids[i] > 0) {
            st.push_back(asteroids[i]);
        } else {
            bool destroyed = false;
            while (!st.empty() && st.back() > 0) {
                if (st.back() < abs(asteroids[i])) {
                    st.pop_back();
                } else if (st.back() == abs(asteroids[i])) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push_back(asteroids[i]);
            }
        }
    }
    return vector<int>(st.begin(), st.end());
}
};
