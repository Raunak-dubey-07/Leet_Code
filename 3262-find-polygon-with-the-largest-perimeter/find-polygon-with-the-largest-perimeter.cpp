class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+(long long)nums[i];
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            if(prefix[i]>nums[i+1]){
                ans= prefix[i]+nums[i+1];
            }
        }
        return ans!=0?ans:-1;
        
    }
};