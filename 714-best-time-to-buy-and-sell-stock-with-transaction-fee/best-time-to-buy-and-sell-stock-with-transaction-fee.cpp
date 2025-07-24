class Solution {
public:
    int solve(vector<int>& prices, int fee,int idx,bool buy,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            int inc=prices[idx]-fee+solve(prices,fee,idx+1,false,dp);
            int ex=solve(prices,fee,idx+1,true,dp);
            return dp[idx][buy]=max(inc,ex);
        }
        else{
            int inc=(-1)*prices[idx]+solve(prices,fee,idx+1,true,dp);
            int ex=solve(prices,fee,idx+1,false,dp);
            return dp[idx][buy]=max(inc,ex);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,fee,0,false,dp);
    }
};