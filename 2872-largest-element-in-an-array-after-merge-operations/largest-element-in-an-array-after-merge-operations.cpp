class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        vector<long long>num(n,0);
        for(int i=0;i<n;i++){
            num[i]=nums[i];
        }
        while(i>0){
            if(num[i]>=num[i-1]){
                num[i-1]=(long long)(num[i]+num[i-1]);
            }
            i--;
        }
        long long maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,1LL*num[i]);
        }
        return maxi;
        
    }
};