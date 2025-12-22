class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;

        }
        int freq=-1;
        int dominant=0;
        for(auto &x:mp){
            freq=max(freq,x.second);
            if(freq==x.second){
                dominant=x.first;
            }
        }
        int total=mp[dominant];
        mp.clear();
        int i=0;
        while(i<n){
            mp[nums[i]]++;
            if(mp[dominant]>((i+1)/2) && (total-mp[dominant])>((n-i-1)/2)){
                return i;
            }
            i++;
        }
        return -1;
        
        
        
    }
};