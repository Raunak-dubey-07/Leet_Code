class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int r,int c,vector<vector<int>>&dp){
        if((r>=obstacleGrid.size() || c>=obstacleGrid[0].size())|| obstacleGrid[r][c]==1){       cout<<"hii"<<endl;
            return 0;
        }
        if(r== obstacleGrid.size()-1 && c==obstacleGrid[0].size()-1){
            cout<<"hii2"<<endl;
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int rt=solve(obstacleGrid,r+1,c,dp);
        int dn=solve(obstacleGrid,r,c+1,dp);
        return dp[r][c]= rt+dn;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};