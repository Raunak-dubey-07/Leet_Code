class Solution {
    private:
bool solve(vector<int>&nums,int idx,vector<int>&dp){
        int n=nums.size();
        if(idx==(n-1)){
            return true;
        }
        if(nums[idx]==0){
            return false;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int reach=idx+nums[idx];
        for(int i=idx+1;i<=reach;i++){
            if(i<nums.size() && solve(nums,i,dp) ){
            return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};