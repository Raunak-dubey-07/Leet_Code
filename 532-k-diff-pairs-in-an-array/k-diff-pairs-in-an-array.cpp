class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        unordered_map<int,bool>vis;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=0;
         int x=0;
            int y=0;
            if(k==0){
                x=1;
                y=1;
            }
        for(int i=0;i<n;i++){
           
            int a=nums[i]+k;
            int b=nums[i]-k;
            if(mp[a]>x && !vis[a+nums[i]]){
                ans++;
                // cout<<nums[i]<<" "<<a<<endl;
                vis[a+nums[i]]=true;
            }
            if(mp[b]>y && !vis[b+nums[i]]){
                ans++;
                vis[b+nums[i]]=true;
                // cout<<nums[i]<<" "<<b<<endl;
            }
         }
        return ans;  
    }
};