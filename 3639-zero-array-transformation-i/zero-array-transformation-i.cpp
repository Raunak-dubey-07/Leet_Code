class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>arr(n,0);
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            arr[a]++;
            if(b+1<n){
                arr[b+1]--;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(nums[i]>sum){
                return false;

            }


        }
        return true;
            
    }
};