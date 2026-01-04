class Solution {
public:
    char dfs(unordered_map<char,vector<char>>&mp,vector<int>&visited,char c){
        char mini=c;
        if(!visited[c-'a']){
            visited[c-'a']=true;
            for(auto &child:mp[c]){
                mini=min(mini,dfs(mp,visited,child));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>>mp;
        int n=s1.size();
        for(int i=0;i<n;i++){
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        
        int m=baseStr.size();
        for(int i=0;i<m;i++){
            vector<int>visited(26,false);
            baseStr[i]=dfs(mp,visited,baseStr[i]);
        }
        return baseStr;
    }
};