class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp,int n,int m){
        
        if(i<0 || i>=n || j<0 || j>=m){
            return INT_MAX;
        }
        if(i==n-1){
           return dp[i][j] = matrix[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int down=solve(matrix,i+1,j,dp,n,m);
        int left=solve(matrix,i+1,j-1,dp,n,m);
        int right=solve(matrix,i+1,j+1,dp,n,m);
        int ans=min({down,left,right});
        if(ans==INT_MAX){
            return dp[i][j]=ans;
        }
        return dp[i][j]=ans+matrix[i][j];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,solve(matrix,0,j,dp,n,m));
        }
        return ans;
        
    }
};