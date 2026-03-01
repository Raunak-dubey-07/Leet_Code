class Solution {
public:
    int solve(string s, unordered_set<string>&st,int start,int end,vector<int>&dp){
    if(start>=end){
        return 0;
    }
    if(dp[start]!=-1){
        return dp[start];
    }
    int ans=1+solve(s,st,start+1,end,dp);
    for(int i=1;i<=end-start;i++){
        string p=s.substr(start,i);
        if(st.find(p)!=st.end()){
           ans=min(ans,solve(s,st,start+i,end,dp));
        }
    }
    return dp[start]=ans;
}
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st;
        int n=dictionary.size();
        int m=s.size();
        vector<int>dp(m,-1);
        for(int i=0;i<n;i++){
            st.insert(dictionary[i]);
        }
        return solve(s,st,0,m,dp);
    }
};