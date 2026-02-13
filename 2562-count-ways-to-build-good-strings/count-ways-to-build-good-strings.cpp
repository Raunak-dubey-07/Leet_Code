class Solution {
public:
    const int mod=1000000007;
    int solve(int low, int high, int zero, int one,int len,vector<int>&dp){
        if(len>high){
            return 0;
        }
        if(len+zero>high && len+one>high){
            return 0;
        }
        if(dp[len]!=-1){
            return dp[len];
        }
        int inc=0;
        int ex=0;
        if(len + zero>=low && len + zero <=high){
            inc=(1+solve(low,high,zero,one,len+zero,dp))%mod;
        }
        else if(len+zero<=high){
            inc=solve(low,high,zero,one,len+zero,dp);
        }
        if(len + one>=low && len + one <=high){
            ex=(1+solve(low,high,zero,one,len+one,dp))%mod;
        }
        else if(len+one<=high){
            ex=solve(low,high,zero,one,len+one,dp);
        }
        return dp[len]=(inc+ex)%mod; 
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high,-1);
        return solve(low,high,zero,one,0,dp);
        
    }
};