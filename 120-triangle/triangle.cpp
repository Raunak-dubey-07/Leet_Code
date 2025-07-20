class Solution {
public:
    int solve(vector<vector<int>>& triangle,int r,int c,vector<vector<int>>&dp){
        if((r>=triangle.size()|| c>=triangle[r].size())){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int lt=triangle[r][c]+solve(triangle,r+1,c,dp);
        int rt=triangle[r][c]+solve(triangle,r+1,c+1,dp);
        return dp[r][c]=min(lt,rt);
    }
    int solveTab(vector<vector<int>>& triangle){
        int n=triangle.size();
         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
         for(int i=triangle.size()-1;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                int lt=triangle[i][j]+dp[i+1][j];
                int rt=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(lt,rt);
            }
         }
         return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return solveTab(triangle); 
    }
};