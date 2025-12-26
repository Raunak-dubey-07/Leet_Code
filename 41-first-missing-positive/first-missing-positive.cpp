class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                flag=true;
                break;
            }
        }
        if(!flag)return 1;
        for(int i=0;i<n;i++){
            if(nums[i]<1 || nums[i]>n){
                nums[i]=1;
            }

        }
        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1;
            if(nums[idx]>0){
                nums[idx]=-nums[idx];
            }

        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
};