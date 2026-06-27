class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int mod=1000000007;
        vector<long long> p2(nums.size() + 1);
p2[0] = 1;
for (int i = 1; i <= nums.size(); i++)
    p2[i] = (p2[i - 1] * 2) % mod;
        long long ans=0;
        
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans = (ans + p2[j - i]) % mod;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
        
    }
};