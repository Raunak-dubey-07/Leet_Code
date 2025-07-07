class Solution {
public:
    int solve(vector<int>& prices,int idx,bool buy,int limit,vector<vector<vector<int>>>&dp){
        if(idx>=prices.size() || limit==0){
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
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
        
    }
};