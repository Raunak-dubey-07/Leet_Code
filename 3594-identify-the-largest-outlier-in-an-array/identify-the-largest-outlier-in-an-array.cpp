class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mp;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            mp[nums[i]*2]++;
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            bool flag=false;
            int x=sum-nums[i];
            if(mp[nums[i]*2]){
                mp[nums[i]*2]--;
                flag=true;
            }
            if(mp[x]>0){
                ans=max(nums[i],ans);
            }
            if(flag)
            mp[nums[i]*2]++;
        }
        return ans;
        
    }
};