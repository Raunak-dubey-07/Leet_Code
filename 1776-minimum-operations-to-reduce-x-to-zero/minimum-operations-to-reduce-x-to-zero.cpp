class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int sum=0;
      for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
      }
      int reqsum=sum-x;
      if(reqsum==0){
        return nums.size();
      }
      int i=0;
      int ans=0;
      sum=0;
      for(int j=0;j<nums.size();j++){
        sum=sum+nums[j];
        while(i<nums.size()&& sum>reqsum){
            sum=sum-nums[i++];
        }
        if(sum==reqsum){
           ans=max(ans,j-i+1);
        }
      }
      if(ans){
        return nums.size()-ans;
      }
      return -1;
    }
};