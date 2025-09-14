class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string top = "ab";
        string bot = "ba";
        int score = 0;
        int paisa = x;
        int taisa = y;
        if (x < y) {
            top = "ba";
            bot = "ab";
            paisa = y;
            taisa = x;
        }
        stack<char> st;
        for (char ch : s) {
            string p;
            if (!st.empty()) {
                p.push_back(st.top());
            }
            p.push_back(ch);

            if (!st.empty() && p == top) {
                score += paisa;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        s = "";
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        st = stack<char>();
        for (char ch : s) {
            string p;
            if (!st.empty()) {
                p.push_back(st.top());
            }
            p.push_back(ch);
            if (!st.empty() && p == top) {
                score += taisa;
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return score;
    }
};