class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        for(int i=0;i<n;i++){
            mp1[s[i]-'a']++;
            mp2[t[i]-'a']++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(mp1[s[i]-'a']>0){
                if(mp1[s[i]-'a']>mp2[s[i]-'a']){
                    ans+=mp1[s[i]-'a']-mp2[s[i]-'a'];
                    mp1[s[i]-'a']=0;
                }
               
            }
        }
        return ans;
        
    }
};