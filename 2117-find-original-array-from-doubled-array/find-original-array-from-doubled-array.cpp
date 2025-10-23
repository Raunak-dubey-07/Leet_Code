class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>mp;
        unordered_map<int,bool>vis;
        vector<int>ans;
        int n=changed.size();
        int zero=0;
        for(int i=0;i<n;i++){
            if(changed[i]==0){
                zero++;
            }
            
                mp[changed[i]]++;
            
        }
        if(zero%2!=0 || n%2!=0){
            return {};
        }
        sort(changed.begin(),changed.end());
        for(int i=0;i<n;i++){
            if(mp[changed[i]] && mp[changed[i]*2]){
                mp[changed[i]]--;
                mp[changed[i]*2]--;
                //cout<<changed[i]<<" ";
                ans.push_back(changed[i]);
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        if((ans.size())==n/2)
        return ans;
        return {};
        
    }
};