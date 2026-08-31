class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j){
        if (i == grid.size() - 1) return grid[i][j];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minCost = INT_MAX;
        int n = grid[0].size();
        for (int k = 0; k < n; ++k) {
            int move = moveCost[grid[i][j]][k];
            minCost = min(minCost, move + solve(grid,moveCost,i + 1, k));
        }

        return dp[i][j]=grid[i][j] + minCost;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int ans = INT_MAX;
        dp.assign(n, vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid[0].size(); i++) {
            ans = min(ans, solve(grid,moveCost,0, i));
        }
        return ans;
        //return solve(grid,moveCost,0,0);

        
    }
};