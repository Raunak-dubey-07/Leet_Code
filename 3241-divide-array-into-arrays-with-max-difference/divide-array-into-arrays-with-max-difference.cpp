class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
         int n=nums.size();
         vector<vector<int>>ans(n/3,vector<int>(3,0));
    bool flag=false;
    int c=0;
    for(int i=0;i<n;i++){
        if((i)%3==0){
            if(abs(nums[i]-nums[i+2])<=k){
                c++; 
            }
            else{
                flag=true;
                ans.clear();
                break;

            }
        }
        ans[c-1][i%3]=nums[i];
    }
    return ans;
    }
};