class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return INT_MIN;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ans1=nums1[i]*nums2[j];
        long long ans2=nums1[i]*nums2[j]+(long long)solve(nums1,nums2,i+1,j+1,n,m,dp);
        long long ans3=solve(nums1,nums2,i,j+1,n,m,dp);
        long long ans4=solve(nums1,nums2,i+1,j,n,m,dp);
        return dp[i][j]=max({ans1,ans2,ans3,ans4});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(nums1,nums2,0,0,n,m,dp);
    }
};