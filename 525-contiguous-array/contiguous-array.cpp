class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        for(int i=0;i<n;i++){
            if(i==0 && nums[i]==0){
                prefix[i]=-1;
            }
            else if(i==0 && nums[i]==1){
                prefix[i]=1;
            }
            else if(nums[i]==0){
                prefix[i]=prefix[i-1]-1;
            }
            else{
                prefix[i]=prefix[i-1]+1;

            }

        }
        unordered_map<int,int>first;
        unordered_map<int,int>second;
        for(int i=0;i<n;i++){
            if(first[prefix[i]]==0){
                first[prefix[i]]=i+1;
            }
            second[prefix[i]]=i+1;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix[i]==0){
                ans=max(ans,i+1);
            }
            else{
                ans=max(ans,i+1-first[prefix[i]]);
            }

        }
        return ans;
        
    }
};