class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<long long>dry;
        unordered_map<long long,long long>mp;
        int n=rains.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                dry.push_back(i);
            }
            else if(mp.find(rains[i])==mp.end()){
                mp[rains[i]]=i;
            }
            else{
                long long x=mp[rains[i]];
                long long idx=lower_bound(dry.begin(),dry.end(),x)-dry.begin(); 
                if(idx>=dry.size()){
                    return { };
                }
                ans[dry[idx]]=rains[i];
                dry.erase(dry.begin()+idx);
                mp[rains[i]]=i;
            }
          
        }
          for(int i=0;i<n;i++){
                if(rains[i]==0 && ans[i]==-1){
                    ans[i]=1;
                }
            }
        return ans;
        
    }
};
