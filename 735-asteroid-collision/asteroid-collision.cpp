class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (st.empty() || (st.top() < 0 && asteroids[i] < 0) ||
                (st.top() > 0 && asteroids[i] > 0) ||
                (st.top() < 0 && asteroids[i] > 0)) {

                st.push(asteroids[i]);
            } else if (!st.empty() && st.top() == (-1 * asteroids[i]) &&
                       st.top() > 0) {
                st.pop();
            } else {
                while (!st.empty() &&
                       ((st.top() > 0 && asteroids[i] < 0) ||
                        (st.top() > 0 && st.top() == (-1 * asteroids[i])))) {
                    if (st.top() > 0 && st.top() == (-1 * asteroids[i])) {
                        st.pop();
                        asteroids[i]=0;
                    } else {
                        int a = st.top();
                        st.pop();
                        if (abs(a) > abs(asteroids[i])) {
                            asteroids[i] = a;
                        }
                    }
                   
                }
                if(asteroids[i]!=0)
                 st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};