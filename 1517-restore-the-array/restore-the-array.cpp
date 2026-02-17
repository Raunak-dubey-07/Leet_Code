class Solution {
public:
    const int mod=1000000007;
    int solve(string&s,int k,int start,vector<int>&dp){
        if(start>=s.size()){
            return 1;
        }
        if(s[start]=='0'){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        long long num=0;
        long long ans=0;
        for(int i=start;i<s.size();i++){
            num=num*10+(s[i]-'0');
            if(num>k){
                break;
            }
            ans=(ans%mod+solve(s,k,i+1,dp))%mod;
        }
        return dp[start]=ans%mod;
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int>ans(n,-1);
        return solve(s,k,0,ans);

        
    }
};