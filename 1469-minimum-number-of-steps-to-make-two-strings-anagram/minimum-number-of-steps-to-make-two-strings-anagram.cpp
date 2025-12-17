class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(mp1[s[i]]>0){
                if(mp1[s[i]]>mp2[s[i]]){
                    ans+=mp1[s[i]]-mp2[s[i]];
                    mp1[s[i]]=0;
                }
               
            }
        }
        return ans;
        
    }
};