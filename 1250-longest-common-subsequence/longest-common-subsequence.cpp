class Solution {
public:
    int solve(string&text1,string&text2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1>=text1.size()|| idx2>=text2.size()){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2]=1+solve(text1,text2,idx1+1,idx2+1,dp);
        }
        
        int a=solve(text1,text2,idx1+1,idx2,dp);
        int b=solve(text1,text2,idx1,idx2+1,dp);
        return dp[idx1][idx2]=max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(text1,text2,0,0,dp);
    }
};