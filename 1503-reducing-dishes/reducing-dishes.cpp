class Solution {
public:
    int solve(int index,int time,vector<vector<int>>&dp,vector<int>&satisfaction){
        int n=satisfaction.size();
        if(index>=n){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        int inc=satisfaction[index]*time+solve(index+1,time+1,dp,satisfaction);
        int ex=0+solve(index+1,time,dp,satisfaction);
        dp[index][time]=max(inc,ex);
        return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,(vector<int>(n+1,-1)));
        return solve(0,1,dp,satisfaction);
        
    }
};