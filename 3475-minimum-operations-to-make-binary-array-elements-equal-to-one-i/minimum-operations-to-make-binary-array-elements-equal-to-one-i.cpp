class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int cnt=0;
        while(i+2<n){
            if(nums[i]==0){
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                cnt++;
            }
            i++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                return -1;
            }
        }
        return cnt;
        
    }
};