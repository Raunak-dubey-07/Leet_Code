class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        long long ans=0;
        for(auto x:mp){
            if(x.second==1){
                return -1;
            }
            if(x.second%3==1){
                int z=(x.second/3)-1;
                ans=ans+z+((x.second-z*3)/2);
            }
            else if(x.second%3==2){
                ans=ans+x.second/3+1;
            }
            else{
                ans=ans+x.second/3;
            }
        }
        return ans;
        
    }
};