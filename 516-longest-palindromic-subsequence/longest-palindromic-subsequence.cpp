class Solution {
public:
    int solve(string s1,string s2){
        int n=s1.size();
        int m=s2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    curr[j]=1+next[j+1];
                }
                else{
                    curr[j]=max(next[j],curr[j+1]);
                }
            }
            next=curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        return solve(s,s1);


        
    }
};