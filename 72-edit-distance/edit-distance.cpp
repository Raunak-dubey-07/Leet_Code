class Solution {
private:
int solve(string &word1,string &word2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1==word1.length()){
            return  word2.length()-idx2;
        }
        
        if(idx2==word2.length()){
            return word1.length()-idx1;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int ans=0;
        if(word1[idx1]==word2[idx2]){
            return solve(word1,word2,idx1+1,idx2+1,dp);
        }
        else{
        
        int in=1+solve(word1,word2,idx1,idx2+1,dp);
        int del=1+solve(word1,word2,idx1+1,idx2,dp);
        int rep=1+solve(word1,word2,idx1+1,idx2+1,dp);
        
        ans= min(in,min(rep,del));
        }
        return dp[idx1][idx2]=ans;
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,0,0,dp);
    }
};