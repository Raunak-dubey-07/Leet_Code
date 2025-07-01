class Solution {
public:
    int solve(vector<int>& prices,int i,bool buy,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
            int inc= (-1)*prices[i]+solve(prices,i+1,0,dp);
            int ex= solve(prices,i+1,1,dp);

            return dp[i][buy]= max(inc,ex);
        }
        else{
            int inc=prices[i]+solve(prices,i+1,1,dp);
            int ex=solve(prices,i+1,0,dp);
            return dp[i][buy]= max(inc,ex);
        }
        // return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
        
    }
};