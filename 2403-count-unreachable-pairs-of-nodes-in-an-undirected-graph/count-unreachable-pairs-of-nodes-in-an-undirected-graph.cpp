class Solution {
public:
    void dfs(unordered_map < int, vector<int>>& adj, vector<int>& visited,
             int s, int &count) {
        visited[s] = true;
        count++;
        for (int i : adj[s])
            if (visited[i] == false)
                dfs(adj, visited, i, count);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        if(edges.size()==0){
            return (1LL*(n-1)*1LL*n)/2;
        }
        vector<int> res;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            int count = 0;
            if (!visited[i]) {
                dfs(mp, visited, i, count);
            }
            if(count>0){
                cout<<count<<endl;
            res.push_back(count);
            }
        }
        long long result=0;
        for (int i = 0; i < res.size(); i++) {
            for (int j = i+1; j <res.size(); j++) {
                long long product=res[i];
                product *= res[j];
                result+=product;
            }
            
        }
        return result;
    }
};