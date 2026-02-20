class Solution {
public: 
    bool check(vector<int>mp1,vector<int>mp2,string p){
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>mp1(26,0);
        int n=p.size();
        for(int i=0;i<n;i++){
            mp1[p[i]-'a']++;
        }
        vector<int>mp2(26,0);
        int j=0;
        int m=s.size();
        int i=0;
        vector<int>res;
        while(j<m){
            mp2[s[j]-'a']++;
            while(mp2[s[j]-'a']>mp1[s[j]-'a']){
                mp2[s[i]-'a']--;
                i++;
            }
            if(check(mp1,mp2,p)){
                res.push_back(i);
            }
            j++;
        }
        return res;
    }
};