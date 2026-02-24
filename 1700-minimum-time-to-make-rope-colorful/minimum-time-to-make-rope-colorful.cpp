class Solution {
public:
    int solve(string& colors, vector<int>& neededTime, int i, int n,char prev,
              vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][prev - 'a'] != -1) {
            return dp[i][prev-'a'];
        }
        int pick =neededTime[i] + solve(colors, neededTime, i + 1, n, prev, dp);
        int not_pick = INT_MAX;
        if (colors[i] != prev) {
            not_pick = solve(colors, neededTime, i + 1, n, colors[i], dp);
        }
        return dp[i][prev-'a'] = min(pick, not_pick);
    }
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(28, -1));
        char prev = '{';
        return solve(colors, neededTime, 0, n, prev, dp);
    }
};