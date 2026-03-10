class Solution {
public:
    int solve(vector<vector<int>>& piles,int i,int k,vector<vector<int>>&dp){
         if(i==piles.size() || k==0)
            return 0;

        if(dp[i][k]!=-1)
            return dp[i][k];

        int ans = solve(piles,i+1,k,dp);

        int sum = 0;

        for(int j=0;j<piles[i].size() && j<k;j++){
            sum += piles[i][j];
            ans = max(ans, sum + solve(piles,i+1,k-j-1,dp));
        }
        return dp[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(piles,0,k,dp);
    }
};