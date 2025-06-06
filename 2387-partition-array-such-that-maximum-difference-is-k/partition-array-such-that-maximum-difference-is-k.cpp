class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=0;
        int c=1;
        for(int i=0;i<n;i++){
                maxi=nums[i];
                if((maxi-mini)>k){
                    c++;
                    mini=nums[i];
                }
        }   
        return c;  
    }
};