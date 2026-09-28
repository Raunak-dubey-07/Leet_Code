class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int id=0;
        vector<int> mp(k, 0);
        for(int i=0;i<n;i++){
            long long sum=0;
            id++;
            for(int j=i;j<n;j++){
                //cout<<j<<endl;
                 int x = nums[j] % k;
                int val = (2LL * x) % k;
                if (val < 0) val += k;

                mp[val]=id;

                sum+=nums[j];
                if(sum%k==0){
                    ans=max(ans,j-i+1);
                    continue;
                }
                int rem=sum%k;
                if(rem<0){
                    rem+=k;
                }
                if(mp[rem]==id ){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
        
    }
};