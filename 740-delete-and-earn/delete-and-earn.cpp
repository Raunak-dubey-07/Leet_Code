class Solution {
public:
    int solve(vector<int>& nums,int i,unordered_map<int,int>&mp,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
       int inc=nums[i]*mp[nums[i]]+solve(nums,i+2,mp,n,dp);
       int ex=solve(nums,i+1,mp,n,dp);
        return dp[i]=max(ex,inc);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        

        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int>vec(maxi+1,0);

        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0){
                vec[nums[i]]=nums[i];
            }
            mp[nums[i]]++;
        }
        int m=vec.size();
        vector<int>dp(m,-1);
        return solve(vec,0,mp,m,dp);
    }
};