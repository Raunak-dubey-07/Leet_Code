class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(k==n){
            return true;
        }
        if(n<k){
            return false;
        }
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int odd=0;
        for(auto x:mp){
            if(x.second%2!=0){
                odd++;
            }
        }
        if(k<odd){
            return false;
        }
        return true;
    }
};