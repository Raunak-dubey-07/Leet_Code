class Solution {
public:
    int solve(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m){
            return INT_MAX;
        }
        if(row==n-1){
            return matrix[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int rightd=solve(matrix,row+1,col+1,dp);
        int leftd=solve(matrix,row+1,col-1,dp);
        int bottom=solve(matrix,row+1,col,dp);
        int next=min(rightd,min(leftd,bottom));
        if(next==INT_MAX){
            return dp[row][col]=INT_MAX;
        }
        return dp[row][col]= matrix[row][col]+next;
    }
   int solveTab(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case: last row = matrix[last row][col]
    for (int j = 0; j < m; j++) {
        dp[n-1][j] = matrix[n-1][j];
    }

    // bottom-up: from row n-2 up to 0
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int rightd = (j+1 < m) ? dp[i+1][j+1] : INT_MAX;
            int leftd  = (j-1 >= 0) ? dp[i+1][j-1] : INT_MAX;
            int bottom = dp[i+1][j];

            int next = min({rightd, leftd, bottom});
            dp[i][j] = (next == INT_MAX ? INT_MAX : matrix[i][j] + next);
        }
    }

    // answer = min of first row
    return *min_element(dp[0].begin(), dp[0].end());
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n=matrix.size();
        // int m=matrix[0].size();
        // int mini=INT_MAX;
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<m;i++){
        //     mini=min(mini,solve(matrix,0,i,dp));
        // }
        // return mini;
        return solveTab(matrix);

        
    }
};