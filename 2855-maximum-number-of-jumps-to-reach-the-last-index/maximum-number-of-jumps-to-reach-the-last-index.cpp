class Solution {
public:
    int solve(vector<int>&nums,int target,int i,int j,vector<vector<int>>&dp){
        if(i==nums.size()-1){
            return 0;
        }
        if(j>=nums.size()||i>=nums.size()){
            return INT_MIN;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }        
        int inc=INT_MIN;
        int ex=INT_MIN;
        if(abs(nums[i]-nums[j])<=target){
            inc=1+solve(nums,target,j,j+1,dp);
            ex=solve(nums,target,i,j+1,dp);
        }
        else{
            ex=solve(nums,target,i,j+1,dp);
        }
        return dp[i][j]=max(inc,ex);

    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int x=solve(nums,target,0,1,dp);
        if(x<=0){
            return -1;
        }
        return x;
    }
};