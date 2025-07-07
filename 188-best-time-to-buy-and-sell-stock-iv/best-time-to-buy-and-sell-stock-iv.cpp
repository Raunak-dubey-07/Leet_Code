class Solution {
public:
    int solve(vector<int>& prices, int idx, bool buy, int limit,
              vector<vector<vector<int>>>& dp) {
        if (idx >= prices.size() || limit == 0) {
            return 0;
        }
        if (dp[idx][buy][limit] != -1) {
            return dp[idx][buy][limit];
        }
        if (buy) {
            int inc = (-1) * prices[idx] + solve(prices, idx + 1, 0, limit, dp);
            int ex = solve(prices, idx + 1, 1, limit, dp);
            return dp[idx][buy][limit] = max(inc, ex);
        } else {
            int inc = prices[idx] + solve(prices, idx + 1, 1, limit - 1, dp);
            int ex = solve(prices, idx + 1, 0, limit, dp);
            return dp[idx][buy][limit] = max(inc, ex);
        }
    }
   int solveTab(vector<int>& prices,int k) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0;
                    if (buy) {
                        int inc = (-1) * prices[idx] + dp[idx + 1][0][limit];
                        int ex = dp[idx + 1][1][limit];
                        profit = max(inc, ex);
                    } else {
                        int inc = prices[idx] + dp[idx + 1][1][limit - 1];
                        int ex = dp[idx + 1][0][limit];
                        profit = max(inc, ex);
                    }
                    dp[idx][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {

        return solveTab(prices,k);
    }
};