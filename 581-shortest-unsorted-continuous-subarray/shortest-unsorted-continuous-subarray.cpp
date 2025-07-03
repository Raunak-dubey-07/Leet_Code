class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if(n==2 && nums[0]>nums[1]){
            return 2;
        }
        int start=0;
        int end=-1;
        vector<int>vec=nums;
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            if(vec[i]!=nums[i]){
                start=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(vec[i]!=nums[i]){
                end=i;
                break;
            }
        }
        return end-start+1;
    }
};