class Solution {
public: 
    bool check(unordered_map<char,int>mp1,unordered_map<char,int>mp2,string p){
        for(int i=0;i<p.size();i++){
            if(mp1[p[i]]!=mp2[p[i]]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp1;
        int n=p.size();
        for(int i=0;i<n;i++){
            mp1[p[i]]++;
        }
        unordered_map<char,int>mp2;
        int j=0;
        int m=s.size();
        int i=0;
        vector<int>res;
        while(j<m){
            mp2[s[j]]++;
            while(mp2[s[j]]>mp1[s[j]]){
                mp2[s[i]]--;
                if(mp2[s[i]]==0){
                    mp2.erase(s[i]);
                }
                i++;
            }
            if(mp1.size()==mp2.size()&&check(mp1,mp2,p)){
                res.push_back(i);
            }
            j++;
        }
        return res;
    }
};