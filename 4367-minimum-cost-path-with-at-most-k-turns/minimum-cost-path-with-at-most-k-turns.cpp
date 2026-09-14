class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j, int k,int d,vector<vector<vector<vector<int>>>>&dp){
        if(k<0 || i<0 || j<0 || i>= grid.size() || j>=grid[0].size()){
            return 1e9;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j][k][d]!=-1){
            return dp[i][j][k][d];
        }
        //up i-1 d==0
        int op1=solve(grid,i-1,j,k-!(d==1 || d==0),1,dp);
        // down =i+1 d==2;
        int op2=solve(grid,i+1,j,k-!(d==2 || d==0),2,dp);
        // right j+1 d==2;
        int op3=solve(grid,i,j+1,k-!(d==3 || d==0),3,dp);
        // left j-1 d==4;
        int op4=solve(grid,i,j-1,k-!(d==4 || d==0),4,dp);
        return dp[i][j][k][d]=grid[i][j]+min({op1,op2,op3,op4});
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(k+1,vector<int>(5,-1))));
         long long x=solve(grid,0,0,k,0,dp);
         if(x>=1e9){
            return -1;
         }
         return (int)x;
    }
};