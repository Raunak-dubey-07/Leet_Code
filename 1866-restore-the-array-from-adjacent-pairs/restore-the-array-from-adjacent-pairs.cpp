class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,int index,unordered_map<int,bool>&visited,vector<int>&ans){
        if(visited[index]){
            return;
        }
        ans.push_back(index);
        visited[index]=true;
        for(auto &child:mp[index]){
            dfs(mp,child,visited,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,bool>visited;
        for(int i=0;i<adjacentPairs.size();i++){
            int u=adjacentPairs[i][0];
            int v=adjacentPairs[i][1];
            mp[v].push_back(u);
            mp[u].push_back(v);
        }
        int first=-1;
        for(auto x:mp){
            if(x.second.size()==1){
                first=x.first;
                break;
            }
        }
        vector<int>ans;
        dfs(mp,first,visited,ans);
        return ans;
    }
};