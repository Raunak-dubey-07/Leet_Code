class Solution {
public:
    vector<vector<int>>result;
    void dfs(unordered_map<int,vector<int>>&adj,int index,vector<int>ans,int n){
        if(index==n-1){
            ans.push_back(n-1);
            result.push_back(ans);
            return;
        }
        ans.push_back(index);
        for(auto neigh:adj[index]){
            dfs(adj,neigh,ans,n);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;
        int n=graph.size();
        for(int i=0;i<graph.size();i++){
            adj[i]=graph[i];
        }
        vector<int>ans;
        dfs(adj,0,ans,n);
        return result;
    }
};