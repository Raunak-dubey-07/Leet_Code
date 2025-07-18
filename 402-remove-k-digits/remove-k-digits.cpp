class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        int i=1;
        string ans;
        stack<char>st;
        st.push(num[0]);
        while(i<n){
            if(num[i]<=st.top() && k){
                while((!st.empty() && k)&&num[i]<st.top()){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
            else{
                st.push(num[i]);
            }
            i++;
        }
        while(k){
            st.pop();
            k--;
        }
        int c=0;
        while(!st.empty()){
            if(st.top()=='0'){
                c++;
            }
            else{
                c=0;
            }
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.size()==0){
            return "0";
        }
        reverse(ans.begin(),ans.end());
        if(ans.substr(c, ans.size()).size()==0){
            return "0";
        }
        
            return ans.substr(c, ans.size());
        
     }
};