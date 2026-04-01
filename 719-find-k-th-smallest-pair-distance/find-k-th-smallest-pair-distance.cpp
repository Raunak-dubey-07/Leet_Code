class Solution {
public:
    bool check(vector<int>& nums, int k,long long mid){
        int i=0;
        int j=i+1;
        long long paircount=0;
        int n=nums.size();
        while(i<n && j<n){
            if((nums[j]-nums[i])<=mid){
                paircount+=(j-i);
                j++;
            }
            else{
                i++;
            }
        }
        if(paircount>=k){
            return true;
        }
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long l=0;
        long long r=*max_element(nums.begin(),nums.end());
        long long ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,k,mid)){
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