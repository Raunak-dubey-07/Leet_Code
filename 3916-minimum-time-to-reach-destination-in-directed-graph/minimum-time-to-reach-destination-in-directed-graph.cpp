class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
         vector<vector<pair<int,pair<int,int>>>> adj(n);

        vector<int> visited(n, INT_MAX);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int s = edges[i][2];
            int e = edges[i][3];

            adj[u].push_back({v, {s, e}});
        }

        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0] = 0;

        while (!q.empty()) {
            int u = q.front().first;
            int t = q.front().second;
            q.pop();

            if (t > visited[u]) continue;

            for (auto x : adj[u]) {
                int v = x.first;
                int s = x.second.first;
                int e = x.second.second;

                int start = max(t, s);

                if (start <= e) {
                    int nt = start + 1;

                    if (nt < visited[v]) {
                        visited[v] = nt;
                        q.push({v, nt});
                    }
                }
            }
        }

        return visited[n - 1] == INT_MAX ? -1 : visited[n - 1];
    }
};