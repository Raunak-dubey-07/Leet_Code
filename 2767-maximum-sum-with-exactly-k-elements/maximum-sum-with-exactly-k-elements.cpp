class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int f=maxi+k-1;
        int r=(maxi*(maxi-1))/2;
        int l=(f*(f+1))/2;
        return l-r;
        
    }
};