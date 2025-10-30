class Solution {
public:
     bool dfs(int v,unordered_map<int, vector<int>>&adj,vector<bool>&vis,vector<bool>&recPath){
        vis[v]=true;
        recPath[v]=true;
        for(int x:adj[v]){
            if(!vis[x]){
                if(dfs(x,adj,vis,recPath)){
                    return true;
                }
            }
            else if(recPath[x]){
                return true;
            }

        }
       recPath[v]=false;
       return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adj;
    for (auto &e :prerequisites) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
    }
    vector<bool>vis(numCourses,false);
    vector<bool>recpath(numCourses,false);
    for(int i=0;i<numCourses;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,recpath)){
                return false;
            }
        }
    }
    return true;
    }
};