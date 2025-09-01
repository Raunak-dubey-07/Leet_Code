class Solution {
public:
   int solve(vector<int>&nums,int rem,int idx,vector<vector<int>>&dp){
    if(idx>=nums.size() ){
        if(rem==0){
            return 0;
        }
        return INT_MIN;
    }
    if(dp[idx][rem]!=-1){
        return dp[idx][rem];
    }
    int inc=nums[idx]+solve(nums,(rem+nums[idx])%3,idx+1,dp);
    int ex=solve(nums,rem,idx+1,dp);
    return dp[idx][rem]=max(inc,ex);
    

   }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(3,-1));
        return solve(nums,0,0,dp);
       
        
    }
};