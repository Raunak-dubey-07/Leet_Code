class Solution {
public:
    void dfs(int i, unordered_set<int>& visited,
             unordered_map<int, vector<int>>& adj) {
        visited.insert(i);
        for (int& v : adj[i]) {
            if (visited.find(v) == visited.end()) {
                dfs(v, visited, adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> adj;
        int n= bombs.size();
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long dis =
                    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                if (r1*r1 >= dis) {
                    adj[i].push_back(j);
                }
            }
        }
        int res = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; i++) {
            //int count = 0;
            
            dfs(i, visited, adj);
            int count = visited.size();
            res = max(res, count);
            visited.clear();
        }
        return res;
    }
};