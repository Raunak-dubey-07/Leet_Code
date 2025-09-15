class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]==')' && open>0){
                string t="";
                while(st.top()!='('){
                    t.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int j=0;j<t.size();j++){
                    st.push(t[j]);
                }
                open--;
            }
            else{
                if(s[i]=='('){
                    open++;
                }
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};