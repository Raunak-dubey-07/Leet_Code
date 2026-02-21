class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            int ans=0;
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++){
                mp[nums[i]]++;
            }
            for(auto x:mp){
                ans=max(ans,x.second);
            }
            return ans;
        }
        sort(nums.begin(),nums.end());
        int j=0;
        int i=0;
        int ans=0;
        while(j<n){
            while(nums[j]-nums[i]>2*k){
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};