class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0;
        int i=0;
        while(sum>=0 && i<n){
            sum+=nums[i];
            // cout<<"sum "<<sum<<endl;
            // cout<<nums[i]<<endl;
            if(sum<=0){
                break;
            }
            i++;
        }
        return i;
        
    }
};