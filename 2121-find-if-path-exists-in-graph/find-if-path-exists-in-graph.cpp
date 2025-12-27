class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        if(source==destination){
            return true;
        }
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto x:adj[front]){
                if(x==destination){
                    return true;
                }
                else if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return false;
    }
};