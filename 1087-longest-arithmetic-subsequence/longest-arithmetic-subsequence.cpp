class Solution {
    public:
 int solve(vector<int>&nums,int diff,int index,unordered_map<int,int>dp[]){
        if(index<0){
            return 0;
        }
        if(dp[index].count(diff)){
            return dp[index][diff];
        }
        int j=index-1;
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(nums[index]-nums[j]==diff){
                ans=max(ans,1+solve(nums,diff,j,dp));
            }
        }
        return dp[index][diff]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        unordered_map<int,int>dp[n+1];
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               // int diff=nums[j]-nums[i];
                ans=max(ans,2+solve(nums,nums[j]-nums[i],i,dp));
                //cout<<ans<<endl;
            }
        }
        return ans;
    }
};