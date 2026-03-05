class Solution {
public:
    
    bool ispalindrome(int i,int j,string&s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=ispalindrome(i,j,s);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        int start=-1;
        int end=-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(i,j,s,dp)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        string ans="";
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
    }
};