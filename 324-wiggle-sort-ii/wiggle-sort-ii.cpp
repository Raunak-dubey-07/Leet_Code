class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(n,0);
        int k=(n-1)/2;
        for(int i=0;i<n;i=i+2){
            ans[i]=nums[k--];
        }
        k=n-1;
        for(int i=1;i<n;i=i+2){
            ans[i]=nums[k--];
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
    }
};