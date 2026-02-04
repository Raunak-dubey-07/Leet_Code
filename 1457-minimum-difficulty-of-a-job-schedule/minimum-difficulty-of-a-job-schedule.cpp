class Solution {
public:
    int solve(vector<int>& jd,int n, int d,int idx,vector<vector<int>>&dp){
        if(d==1){
            int ans=jd[idx];
            for(int i=idx;i<n;i++){
                ans=max(ans,jd[i]);
            }
            return ans;
        }
        if(dp[d][idx]!=-1){
            return dp[d][idx];
        }
        int finalResult=INT_MAX;
        int maxi=jd[idx];
        for(int i=idx;i<=n-d;i++){
            maxi=max(maxi,jd[i]);
            int result=maxi+solve(jd,n,d-1,i+1,dp);
            finalResult=min(finalResult,result);
        }
        return dp[d][idx]=finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n){
            return -1;
        }
        vector<vector<int>>dp(d+1,vector<int>(n,-1));
        return solve(jobDifficulty,n,d,0,dp);
        
    }
};