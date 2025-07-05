class Solution {
public:
    
    int specialTriplets(vector<int>& nums) {
        const long long mod=1e9+7;
        unordered_map<long long,long long>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        long long ans=0;
        unordered_map<long long,long long>mp2;
        mp2[nums[0]]++;
        for(int i=1;i<n-1;i++){
            if(mp2[nums[i]*2]>0){
                if((mp[nums[i]*2]-mp2[nums[i]*2])>0){
                    if(nums[i]==0){
                        ans=(ans+(mp2[nums[i]*2]*(mp[nums[i]*2]-mp2[nums[i]*2]-1))%mod)%mod;
                    }
                    else{
                    ans=(ans+(mp2[nums[i]*2]*(mp[nums[i]*2]-mp2[nums[i]*2]))%mod)%mod;
                    }
                }
            }
            mp2[nums[i]]++;

        }
        return (ans%mod);
    }
};