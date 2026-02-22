class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=1;
        mp[s[0]]++;
        for(int i=1;i<n;i++){
            mp[s[i]]++;
            prefix[i]=mp.size();
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            mp[s[i]]++;
            suffix[i]=mp.size();
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(prefix[i]==suffix[i+1]){
                ans++;
            }
        }
        return ans;
        
    }
};