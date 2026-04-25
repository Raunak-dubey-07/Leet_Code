class Solution {
public:
    long long solve(vector<int>&nums,int x, int parity,int i,vector<vector<long long>>&dp){
        int n=nums.size();
        if(i>=n){
            return 0;
        }
        if(dp[i][parity]!=-1){
            return dp[i][parity];
        }
        if(nums[i]%2==parity){
            return dp[i][parity]=nums[i]+solve(nums,x,parity,i+1,dp);
        }
        
        if(nums[i]%2!=parity){
            long long a=solve(nums,x,parity,i+1,dp);
            long long b=nums[i]-x+solve(nums,x,!parity,i+1,dp);
            return dp[i][parity]=max(a,b);
        }
        return 0;

    }
    long long maxScore(vector<int>& nums, int x) {
        int parity=nums[0]%2;
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return solve(nums,x,parity,0,dp);
        
        
    }
};