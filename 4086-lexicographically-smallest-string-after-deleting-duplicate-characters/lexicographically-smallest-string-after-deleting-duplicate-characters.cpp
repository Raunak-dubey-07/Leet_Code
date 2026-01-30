class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        
        unordered_map<char,int>mp;
        for(char&c:s){
            mp[c]++;
        }
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty()|| st.top()<=s[i]){
                st.push(s[i]);
                
            }
            else{
                while(!st.empty() && st.top()>s[i] && mp[st.top()]>1){
                    mp[st.top()]--;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
            while(!st.empty()&&mp[st.top()]>=2){
                mp[st.top()]--;
                st.pop();
            }
            string ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};