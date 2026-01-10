class Solution {
public:
    bool isSimilar(string s1,string s2){
        int n=s1.size();
        int diff=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                diff++;
            }
        }
        return diff==2||diff==0;
    }
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&visited,int node){
        visited[node]=true;
        for(auto &x:adj[node]){
            if(!visited[x])
            dfs(adj,visited,x);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
            
        }
        return count;
        
    }
};