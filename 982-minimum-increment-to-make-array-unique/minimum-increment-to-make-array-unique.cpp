class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //unordered_map<int, int> mp;
        int c = 0;
        for (int i = 0; i < n-1; i++) {
            if(nums[i]>=nums[i+1]){
                int k=nums[i+1];
                nums[i+1]=nums[i]+1;
                c+=nums[i+1]-k;
            }
        }
        return c;
    }
};