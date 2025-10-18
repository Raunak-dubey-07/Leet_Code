class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=value-abs(nums[i])%value;
            }
        }
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]%value<<endl;
            mp[abs(nums[i])%value]++;
        }
        for(int i=0;i<n;i++){
            if(mp[abs(i)%value]==0){
                return i;
            }
            mp[(abs(i)%value)]--;
        }
        return n;
        
    }
};