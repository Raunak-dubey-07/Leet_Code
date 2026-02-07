class Solution {
public:
    int bfs(vector<vector<pair<int, int>>>& adj, int start, int dis, int n) {
        int V = adj.size();
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        int src = start;
        int ans = 0;
        int d = 0;
        dist[src] = 0;
        // cout<<src<<endl;
        q.push({0, src});
        while (!q.empty()) {
            int d = q.front().first;
            int u = q.front().second;
            // cout<<u<<endl;
            q.pop();
            for (auto x : adj[u]) {
                int v = x.first;
                int wt = x.second;
                if (dist[u] + wt < dist[v] && dist[u] + wt <= dis) {
                    // cout << u << " " << v << endl;
                    dist[v] = dist[u] + wt;
                    q.push({dist[v], v});
                }
            }
        }
        cout<<"start "<<start<<endl;
        for(int i=0;i<n;i++){
            cout<<dist[i]<<endl;
            if(dist[i]!=INT_MAX){
                ans++;
            }
        }

        return ans-1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int res=-1;
        for (int i = 0; i < n; i++) {
            int x = bfs(adj, i, distanceThreshold, n);
            ans = min(ans, x);
            if(ans==x){
                res=i;

            }
        }
        return res;
    }
};