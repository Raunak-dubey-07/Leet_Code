class Solution {
public:
    bool hasDuplicate(string&s1,string&s2){
        vector<int>freq(26,0);
        int n1=s1.size();
        int n2=s2.size();
        for(int i=0;i<n1;i++){
            freq[s1[i]-'a']++;
            if(freq[s1[i]-'a']>1){
                return true;
            }
        }
        for(int i=0;i<n2;i++){
            freq[s2[i]-'a']++;
            if(freq[s2[i]-'a']>1){
                return true;
            }
        }
        return false;
    }
    int solve(vector<string>& arr,int n,int i,string temp,unordered_map<string,int>&mp){
        if(i>=n){
            return temp.size();
        }
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        if(!hasDuplicate(temp,arr[i])){
            int inc=solve(arr,n,i+1,temp+arr[i],mp);
            int ex=solve(arr,n,i+1,temp,mp);
            return mp[temp]=max(inc,ex);
        }
        else{
            return mp[temp]=solve(arr,n,i+1,temp,mp);
        }
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        unordered_map<string,int>mp;
        // vector<vector<int>>dp(n,vector<string>(n*n,-1));
        return solve(arr,n,0,temp,mp);
        
    }
};