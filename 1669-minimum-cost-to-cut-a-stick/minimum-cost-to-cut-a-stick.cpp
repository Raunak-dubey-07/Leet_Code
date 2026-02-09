class Solution {
public:
    int solve(vector<int>& cuts,int st,int end,vector<vector<int>>&dp){
        if(st>end){
            return 0;
        }
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
        int ans=INT_MAX;
        for(int i=st;i<=end;i++){
            int ans1=cuts[end+1]-cuts[st-1]+solve(cuts,st,i-1,dp)+solve(cuts,i+1,end,dp);
            ans=min(ans,ans1);
        }
        return dp[st][end]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
     int m=cuts.size();
    vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(cuts, 1, cuts.size() - 2,dp);
    }
};