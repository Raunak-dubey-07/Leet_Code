class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        long long maxi=*max_element(nums.begin(),nums.end())+k;
        vector<int>arr(maxi+2,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=max(0,nums[i]-k);
            int b=nums[i]+k+1;
            arr[a]++;
            arr[b]--;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        long long ans=0;
        long long res=0;
        for(int i=0;i<arr.size();i++){
            ans=ans+arr[i];
            // cout<<i<<" "<<ans<<endl;
            // cout<<"op "<<numOperations+mp[i]<<endl;
            res=max(res,min(ans,1LL*numOperations+mp[i]));
        }
        return res;
    }
};