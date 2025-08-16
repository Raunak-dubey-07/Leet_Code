class Solution {
public:
    string smallestSubsequence(string s) {
         vector<char> st;
         int n=s.size();
         unordered_map<char,int>mp;
         unordered_map<char,bool>flag;
         for(int i=0;i<n;i++){
            mp[s[i]]++;
         }
        // && mp[c]>1 && flag[c]
        for (auto &c : s) {
             mp[c]--;
            if(flag[c]){
                continue;
            }
            while (!st.empty() && st.back() > c && mp[st.back()]>0 ) {
                
                flag[st.back()]=false;
                st.pop_back();
            }
             st.push_back(c);
            
             flag[c]=true;
        }
        string ans="";
        for(int i=0;i<st.size();i++){
            ans.push_back(st[i]);
        }
        return ans;

    }
};