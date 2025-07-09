class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        long long total=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]*i;
            total+=nums[i];
        }
        long long maxi=sum;
        for(int i=1;i<n;i++){
            sum=sum+total-(n*(nums[n-i]));
            maxi=max(sum,maxi);
        }
        return maxi;
        
        
    }
};