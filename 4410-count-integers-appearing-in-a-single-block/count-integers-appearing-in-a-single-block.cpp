class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            else if(mp[nums[i]]==0){
                ans++;
                mp[nums[i]]++;
            }
            else if(mp[nums[i]]>0){
                ans--;
                mp[nums[i]]=-1e9;
            }
        }
        if(mp[nums[n-1]]==0){
            ans++;
        }
        else if(mp[nums[n-1]]>0){
            ans--;
        }
        return ans;
        
    }
};