class Solution {
public:
    void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
      //  cout << u << " ";  // process node

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        vector<bool>visited(n,false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] != 0) {
                    adjList[i].push_back(j);
                }
            }
        }
        int count=0;
       for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, adjList, visited);
            count++;
        }
    }
    return count;
    }
};