class Solution {
public:
    int solve(vector<int>&prices,bool buy,int idx,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            int inc=(-1)*prices[idx]+solve(prices,0,idx+1,dp);
            int ex=solve(prices,1,idx+1,dp);
            return dp[idx][buy]= max(inc,ex);
        }
        else{
            int inc=prices[idx]+solve(prices,1,idx+2,dp);
            int ex=solve(prices,0,idx+1,dp);
            return dp[idx][buy]= max(inc,ex);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,1,0,dp);  
    }
};