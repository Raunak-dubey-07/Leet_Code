class Solution {
public:
    bool solve(vector<int>& nums, vector<vector<int>>& queries,int n){
        vector<int>arr(nums.size(),0);
        for(int i=0;i<n;i++){
            int a=queries[i][0];
            int b=queries[i][1];
            int val=queries[i][2];
            //cout<<a<<endl;
            arr[a]+=val;
            if(b+1<nums.size()){
                arr[b+1]-=val;
            }
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
             sum+=arr[i];
             if(nums[i]>sum){
                return false;
             }
        }
        return true;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0;
        int r=queries.size();
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(solve(nums,queries,mid)){
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