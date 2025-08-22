class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        sort(nums.begin(),nums.end());
        int ans=0;
        while(j<n){
            if(nums[i]<nums[j]){
                i++;
                j++;
                ans++;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
};