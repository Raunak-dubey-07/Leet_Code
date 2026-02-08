class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;

        for (int x : nums) {
            long long a = x;
            while (!st.empty() && st.top() == a) {
                a += st.top() ;
                st.pop();
            }
            st.push(a);
        }

        vector<long long> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
}
;