class Solution {
public:
    int solve(vector<int>& slices,int index,int end,int k,vector<vector<int>>&dp){
        int n=slices.size();
        if(k==0||index>end){
            return 0;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        int inc=slices[index]+solve(slices,index+2,end,k-1,dp);
        int ex=0+solve(slices,index+1,end,k,dp);
        return dp[index][k]=max(inc,ex);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        int n=k/3;
        vector<vector<int>>dp(k,vector<int>(n+1,-1));
        int case1=solve(slices,1,k-1,k/3,dp);
        vector<vector<int>>dp1(k,vector<int>(n+1,-1));
        int case2= solve(slices,0,k-2,k/3,dp1);
        return max(case1,case2);
    }
};