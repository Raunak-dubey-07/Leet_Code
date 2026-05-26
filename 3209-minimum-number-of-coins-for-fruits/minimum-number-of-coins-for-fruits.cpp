class Solution {
public:
    int solve(vector<int>& prices,vector<int>&dp,int i){
      
        int n = prices.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for (int j = i; j <= min(n - 1, 2 * i + 1); j++) {

            ans = min(ans,
                      prices[i] + solve(prices, dp, j + 1));
        }

        return dp[i] = ans;
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,-1);
        return solve(prices,dp,0);        
    }
};