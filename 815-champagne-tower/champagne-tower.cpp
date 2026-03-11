class Solution {
public:
double solve(int poured, int query_row, int query_glass,vector<vector<double>>&dp){
    if(query_glass > query_row || query_glass<0 || query_row<0){
        return 0;
    }
    if(query_row==0 && query_glass==0){
        return poured;
    }
    if(dp[query_row][query_glass]!=-1){
        return dp[query_row][query_glass];
    }
    return dp[query_row][query_glass]=(max(0.00,(solve(poured,query_row-1,query_glass-1,dp)-1)/2))+max(0.00,(solve(poured,query_row-1,query_glass,dp)-1)/2);
}
    double champagneTower(int poured, int query_row, int query_glass) {
       vector<vector<double>> dp(query_row+1, vector<double>(query_row+1,-1));
        return min(1.0,solve(poured,query_row,query_glass,dp));    
    }
};