class Solution {
public:
    int solve(vector<int>&satisfaction){
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,(vector<int>(n+2,0)));
       for(int index=n-1;index>=0;index--){
        for (int time = index+1; time >= 1; time--) {
            int inc = satisfaction[index] * time + dp[index + 1][time + 1];
            int ex = dp[index + 1][time];
            dp[index][time] = max(inc, ex);
        }
      
       }
          return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        
        return solve(satisfaction);
        
    }
};