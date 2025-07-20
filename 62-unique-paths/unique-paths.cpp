class Solution {
public:
   int solve(int row, int col, int m, int n, vector<vector<int>>& dp) {
    if(row == m && col == n){
        return 1;
    }
    if(row > m || col > n){
        return 0;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    int r = solve(row, col + 1, m, n, dp);
    int d = solve(row + 1, col, m, n, dp);
    return dp[row][col] = r + d;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m-1,n-1,dp);

    }
};