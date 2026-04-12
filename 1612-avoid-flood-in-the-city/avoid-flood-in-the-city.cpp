class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<long long>dry;
        unordered_map<long long,long long>mp;
        int n=rains.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                dry.insert(i);
            }
            else if(mp.find(rains[i])==mp.end()){
                mp[rains[i]]=i;
            }
            else{
                long long x=mp[rains[i]];
                auto it = dry.lower_bound(x);
                if(it == dry.end())
                    return {};

                ans[*it] = rains[i];
                dry.erase(it);
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
