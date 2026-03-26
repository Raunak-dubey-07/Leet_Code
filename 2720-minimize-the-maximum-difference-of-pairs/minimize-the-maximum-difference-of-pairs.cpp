class Solution {
public:
    bool check(vector<int>& nums, int p,long long mid){
        int i=0;
        int n=nums.size();
        int pairs=0;
        while(i<n-1){
            if(abs(nums[i]-nums[i+1])<=mid){
                pairs++;
                i=i+2;
            }
            else{
                i++;
            }
        }
        return pairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long l=0;
        long long r=nums[n-1]-nums[0];
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(nums,p,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};