class Solution {
public:
    int solve(vector<int>& cost, vector<int>& time,int idx,int total,int n, vector<vector<int>>&dp){
        if(total<=0){
            return 0;
        }
        if(idx>=n){
            return INT_MAX;
        }
        if(dp[idx][total]!=-1){
            return dp[idx][total];
        }
        long long take=cost[idx]+(long long)solve(cost,time,idx+1,total-time[idx]-1,n,dp);
        long long not_take=solve(cost,time,idx+1,total,n,dp);
        return dp[idx][total]=min(take,not_take);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(cost,time,0,n,n,dp);
        
    }
};