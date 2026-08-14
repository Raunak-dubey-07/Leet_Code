class Solution {
public:
    bool solve(vector<int>&stones,unordered_map<int,int>&mp,vector<vector<int>>&dp,int i,int k){
        int n=stones.size();
        if(i>=n){
            return false;
        }
        if(i==n-1){
            return true;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int op1=false;
        int op2=false;
        int op3=false;
        if(k>0 && mp[stones[i]+k]>0){
            op1=solve(stones,mp,dp,mp[stones[i]+k],k);
        }
        if(k-1>0 && mp[stones[i]+k-1]>0 ){
            op2=solve(stones,mp,dp,mp[stones[i]+k-1],k-1);
        }
        if(k+1>0 && mp[stones[i]+k+1]>0){
            op3=solve(stones,mp,dp,mp[stones[i]+k+1],k+1);
        }
        return dp[i][k]=(op1 || op2 || op3);

    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(stones, mp, dp, 0, 0);
        
    }
};