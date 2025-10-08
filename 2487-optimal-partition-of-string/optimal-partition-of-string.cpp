class Solution {
public:
    int partitionString(string s) {
        unordered_map<int,int>mp;
        int n=s.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>0){
                mp.clear();
                ans++;
                mp[s[i]]++;
            }
            else{
                mp[s[i]]++;
            }
        }
        if(mp.size()>0){
            ans++;
        }
        return ans;

        
    }
};