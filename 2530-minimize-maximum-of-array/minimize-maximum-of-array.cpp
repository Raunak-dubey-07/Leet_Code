class Solution {
public:
    bool isValid(vector<int>&nums,long long expected){
    vector<long long> arr(begin(nums), end(nums));
        int n=arr.size();

        for(int i=0;i<n-1;i++){
            if(arr[i]>expected){
                return false;
            }
            long long x=expected-arr[i];
            arr[i+1]=arr[i+1]-x;
        }
        return arr[n-1]<=expected;
    }
    // bool isValid(vector<int> &nums, int mid_max) {
        
    //     vector<long long> arr(begin(nums), end(nums));
    //     int n=arr.size();
    //     for(int i = 0; i<n-1; i++) {
            
    //         if(arr[i] > mid_max)
    //             return false;
            
    //         long long buffer = mid_max - arr[i];
            
    //         arr[i+1] = arr[i+1] - buffer;   
            
    //     }
        
    //     return arr[n-1] <= mid_max;
        
    // }
    int minimizeArrayValue(vector<int>& nums) {
        long long l=0;
        long long r=*max_element(nums.begin(),nums.end());
        long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(isValid(nums,mid)){
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