class Solution {
public:
    typedef long long ll;

    pair<ll,ll> solve(vector<vector<int>>& grid, int i, int j, vector<vector<pair<ll,ll>>>& dp){
        if(i >= grid.size() || j >= grid[0].size()){
            return {LLONG_MIN, LLONG_MAX};
        }
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return {grid[i][j], grid[i][j]};
        }
        if(dp[i][j].first != LLONG_MIN){
            return dp[i][j];
        }

        auto right = solve(grid, i, j+1, dp);
        auto down  = solve(grid, i+1, j, dp);
        ll maxi = max(right.first, down.first);
        ll mini = min(right.second, down.second);
        ll val = grid[i][j];

        if(val >= 0){
            maxi = maxi * val;
            mini = mini * val;
        }
        else{
            ll temp = maxi;
            maxi = mini * val;
            mini = temp * val;
        }
        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>>(m, {LLONG_MIN, LLONG_MAX}));

        ll x = solve(grid, 0, 0, dp).first;
        return x < 0 ? -1 : x % MOD;
    }
};