class Solution {
public:

    // int solve(string &s,string &t,int idx,string &ans){
    //     if(ans==t){
    //         return 1;
    //     }
    //     if(idx>=s.size()){
    //         return 0;
    //     }
    //     int ex=solve(s,t,idx+1,ans);
    //     ans.push_back(s[idx]);
    //     int inc=solve(s,t,idx+1,ans);
    //     ans.pop_back();
    //     return inc+ex;
    // }
    // int numDistinct(string s, string t) {
    //     string ans="";
    //     vector
    //     return solve(s,t,0,ans);
        
    // }


    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
    if(j == t.size()) return 1;         // matched full t
    if(i == s.size()) return 0;         // s exhausted
    if(dp[i][j] != -1) return dp[i][j];

    int ways = 0;
    if(s[i] == t[j])
        ways += solve(s, t, i+1, j+1, dp);  // take s[i]
    
    ways += solve(s, t, i+1, j, dp);        // skip s[i]

    return dp[i][j] = ways;
}

int numDistinct(string s, string t) {
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return solve(s, t, 0, 0, dp);
}
};