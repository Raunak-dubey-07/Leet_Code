class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=maxi){
                maxi=nums[i];
                c++;
            }
        }
        return c;
    }
};