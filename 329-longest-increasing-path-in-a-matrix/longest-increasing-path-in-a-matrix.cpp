class Solution {
public:
    int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1=1;
        int op2=1;
        int op3=1;
        int op4=1;
        if(i+1<n && matrix[i+1][j]>matrix[i][j]){
            op1=1+solve(matrix,i+1,j,dp);
        }
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            op2=1+solve(matrix,i-1,j,dp);
        }
        if(j+1<m && matrix[i][j+1]>matrix[i][j]){
            op3=1+solve(matrix,i,j+1,dp);
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            op4=1+solve(matrix,i,j-1,dp);
        }
        return dp[i][j]=max({op1,op2,op3,op4});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                ans=max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans;
    }
};