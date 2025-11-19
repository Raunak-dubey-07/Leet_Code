class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){

            mp[nums[i]]++;
        }
        while(mp[original]>0){
            original=2*original;
        }
        return original;
        
    }
};