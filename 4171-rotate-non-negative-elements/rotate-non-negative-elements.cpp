class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>pos;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
        }
        int m=pos.size();
        if(m==0){
            return nums;
        }
        k=k%m;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i]=pos[k++%m];
            }
        }
        return nums;
        
    }
};