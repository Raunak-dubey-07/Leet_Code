class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool flipped=false;
        int step=0;
        for(int i=0;i<n;i++){
            if(!flipped && nums[i]==1){
                continue;
            }
            else if(flipped && nums[i]==0){
                continue;
            }
            step++;
            flipped=!flipped;            
        }
        return step;
    }
};