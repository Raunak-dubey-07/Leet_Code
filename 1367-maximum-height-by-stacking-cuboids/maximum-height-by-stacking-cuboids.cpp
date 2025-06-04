class Solution {
public:
    int solveTab(vector<vector<int>>& cuboids){
        int n=cuboids.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int inc=0;
                if(prev==-1||(cuboids[curr][0]>=cuboids[prev][0]&&cuboids[curr][1]>=cuboids[prev][1]&&cuboids[curr][2]>=cuboids[prev][2])){
                inc=cuboids[curr][2]+dp[curr+1][curr+1];
                }
                int ex=dp[curr+1][prev+1];
                dp[curr][prev+1]=max(inc,ex);
            }
        }
        return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids){
            sort(a.begin(),a.end());

        }
        sort(cuboids.begin(),cuboids.end());
       return solveTab(cuboids);

        
    }
};