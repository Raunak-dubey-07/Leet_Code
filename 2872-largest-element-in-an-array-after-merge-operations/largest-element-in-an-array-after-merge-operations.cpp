class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
       long long ans=0;
        while(i>=0){
            if(nums[i]<=ans){
                ans=(long long)(nums[i]+ans);
            }
            else{
                ans=nums[i];
            }
            i--;
        }
        return ans;
    }
};