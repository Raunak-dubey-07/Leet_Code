class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int total=nums[i]+nums[j]+nums[k];
                if(total==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1] ){
                        j++;
                    }
                    j++;
                    k--;
                }
                else if(total>0){
                    k--;
                }
                else{
                    j++;
                }

            }
            
        }
        return res;
    }
};