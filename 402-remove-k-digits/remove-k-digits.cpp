class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            if (st.empty() && num[i] == '0') {
                continue;
            } else if (st.empty()) {
                st.push(num[i]);
            }

            else {
                while (k && !st.empty() && st.top() > num[i]) {
                    st.pop();
                    k--;
                    if (k == 0) {
                        break;
                    }
                }
                st.push(num[i]);
            }
            cout<<st.top()<<endl;
        }
        while (k && !st.empty()) {
            st.pop();
            k--;
        }
        if (st.empty()) {
            return "0";
        } else {
            string s="";
            string p="";
            while (!st.empty()) {
                p +=st.top();
                if(st.top()!='0'){
                    s+=p;
                    p="";
                }
                st.pop();
            }
            if(s.empty()){
                return "0";
            }
            reverse(s.begin(), s.end());
            return s;
        }
    }
};