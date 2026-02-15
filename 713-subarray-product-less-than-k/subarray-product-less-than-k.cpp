class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
        int i=0;
        int prod=1;
        int ans=0;
        while(j<n && i<n){
            prod=prod*nums[j];
            cout<<prod<<endl;
            if(prod<k){
                ans+=j-i+1;
               
            }
            else{
                while(prod>=k&& i<=j){
                prod=prod/nums[i];
                i++;
                }
                ans+=j-i+1;
            }
             j++;

        }
        return ans;
        
    }
};