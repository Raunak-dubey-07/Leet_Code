class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& visited,
             vector<int>& color) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        color[start]=0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = 1;
                     q.push(neigh);
                }
                 if (color[neigh] != color[node]) {
                        
                        color[neigh] = !color[node];
                       

                    } else {
                        return false;
                    }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!bfs(i, adj, visited, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};