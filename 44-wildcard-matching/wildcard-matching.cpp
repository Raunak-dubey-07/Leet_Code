class Solution {
public:
    bool solve(string&s,string&p,int i,int j,vector<vector<int>>&dp){
        if(i==s.size() && j== p.size()){
            return true;
        }
        if(i>=s.size() && j<p.size()){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*'){
                    return false;
                }
                
            }
            return true;
        }
        if(j>=p.size() && i<s.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j]){
            return dp[i][j]=solve(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='?'){
            return dp[i][j]=solve(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*'){
            int emp=solve(s,p,i,j+1,dp);
            int cha=solve(s,p,i+1,j,dp);
            return dp[i][j] = emp||cha;
        }
        else{
            return dp[i][j]= false;
        }

    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,p,0,0,dp);

        
    }
};