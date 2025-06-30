class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int pos=0;
        int n=nums.size();
        long long prod=1;
        int zero=0;
        int c=0;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
            prod=prod*nums[i];
            c++;
            }
            if(nums[i]>=0){
                pos++;
            }
        }
        //cout<<prod<<endl;
        int neg=n-pos;
        if(c==0){
            return 0;
        }
        if(neg%2==0){
            return prod;
        }
        else{
            int mini=INT_MIN;
            for(int i=0;i<n;i++){
                if(nums[i]<0)
                mini=max(mini,nums[i]);
                if(nums[i]<=0){
                    zero++;
                }
            }
            if(zero==n && neg==1 && zero!=neg){
                return 0;
            }
            return (prod/mini);
        }
    }
};