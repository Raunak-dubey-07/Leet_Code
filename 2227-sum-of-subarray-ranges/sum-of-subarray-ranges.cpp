class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long maxi=nums[i];
            long long mini=nums[i];
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,1LL*nums[j]);
                mini=min(mini,1LL*nums[j]);
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};