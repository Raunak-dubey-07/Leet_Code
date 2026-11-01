class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long c=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                ans+=((c*(c+1))/2);
                c=0;
            }
            else{
                c++;
            }
        }
        ans+=((c*(c+1))/2);
        return ans;
        
    }
};