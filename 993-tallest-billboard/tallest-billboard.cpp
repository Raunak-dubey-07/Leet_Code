class Solution {
public:
    int solve(vector<int>& rods,int i,int diff,int n,vector<vector<int>>&dp){
        if(i>=n){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][diff+5000]!=-1){
            return dp[i][diff+5000];
        }
        int nothing=solve(rods,i+1,diff,n,dp);
        int ans1=rods[i]+solve(rods,i+1,diff+rods[i],n,dp);
        int ans2=rods[i]+solve(rods,i+1,diff-rods[i],n,dp);
        return dp[i][diff+5000]=max({nothing,ans1,ans2});
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<vector<int>>dp(n,vector<int>(10001, -1));
        return solve(rods,0,0,n,dp)/2;
    }
};