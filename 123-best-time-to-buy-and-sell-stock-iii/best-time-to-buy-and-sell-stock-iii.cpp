class Solution {
public:
    int solve(vector<int>&prices,int idx,bool buy,int limit,vector<vector<vector<int>>>&dp){
        if(idx==prices.size()|| limit==0){
            return 0;
        }
        if(dp[idx][buy][limit]!=-1){
            return dp[idx][buy][limit];
        }
        if(buy){
            int inc=(-1)*prices[idx]+solve(prices,idx+1,0,limit,dp);
            int ex=solve(prices,idx+1,1,limit,dp);
            return dp[idx][buy][limit]=max(inc,ex);
        }
        else{
            int inc=prices[idx]+solve(prices,idx+1,1,limit-1,dp);
            int ex=solve(prices,idx+1,0,limit,dp);
            return dp[idx][buy][limit]=max(inc,ex);
        }
        return 0;
    }
    int solveTab(vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                     int profit=0;
                    if(j){
                       
                        int inc=(-1)*prices[i]+dp[i+1][0][k];
                        int ex=dp[i+1][1][k];
                        profit=max(inc,ex);

                    }
                    else{
                        int inc=prices[i]+dp[i+1][1][k-1];
                        int ex=dp[i+1][0][k];
                        profit=max(inc,ex);
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
        
    }
};