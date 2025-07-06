class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        vector<int>prefix(n,0);
        int sum=0;
        int j=-1;
        bool flag=true;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum;
            if(sum>=target && flag){
                j=i;
                flag=false;
            }
        }
        if(j==-1){
            return 0;
        }
        int ans=j+1;
        int i=0;
        
        
        while(i<j && j<n){
            int curr=prefix[j]-prefix[i];
            if(curr>=target){
                ans=min(ans,j-i);
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
};