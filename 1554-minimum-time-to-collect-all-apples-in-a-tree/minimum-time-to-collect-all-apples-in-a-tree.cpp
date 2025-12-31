class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&adj,int index,int par,vector<bool>&hasApple){
        int time=0;
        for(int &child:adj[index]){
            if(child==par){
                continue;
            }
            int child_time=dfs(adj,child,index,hasApple);
            if(child_time || hasApple[child]){
                time+=2+child_time;
            }
            //cout<<index<<" "<<time<<" "<<child_time<<endl;

        }
        return time;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj,0,-1,hasApple);
    }
};