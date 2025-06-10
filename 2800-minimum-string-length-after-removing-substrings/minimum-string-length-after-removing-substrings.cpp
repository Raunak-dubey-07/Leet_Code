class Solution {
public:
    int minLength(string s) {
        stack<int>st;
        int n=s.size();
        int i=0;
        while(i<n){
            if(!st.empty() && ((st.top()=='A' && s[i]=='B')|| (st.top()=='C' && s[i]=='D'))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string k="";
        while(!st.empty()){
            k.push_back(st.top());
            st.pop();
        }
        return k.size();
    }
};