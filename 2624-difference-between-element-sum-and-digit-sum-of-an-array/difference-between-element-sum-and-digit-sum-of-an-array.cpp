class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int digitsum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(nums[i]!=0){
                int x=nums[i]%10;
                    digitsum+=x;
                nums[i]=nums[i]/10;
            }
        }
        cout<<digitsum<<endl;
        return abs(sum-digitsum);
        
    }
};