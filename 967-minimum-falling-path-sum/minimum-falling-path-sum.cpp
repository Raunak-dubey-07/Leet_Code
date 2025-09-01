
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
        if(dp[row][col]!=INT_MAX){
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++){
            mini=min(mini,solve(matrix,0,i,dp));
        }
        return mini;

        
    }
};