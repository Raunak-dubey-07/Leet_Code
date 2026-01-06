class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, int>>>& mp,
             vector<bool>& visited, int s, int& mini) {
        visited[s] = true;
        for (auto i : mp[s]) {
            cout << i.first << endl;
            if (visited[i.first] == false) {
                mini = min(mini, i.second);
                dfs(mp, visited, i.first, mini);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < roads.size(); i++) {
            mp[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            mp[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<bool> visited(n+1, 0);
        int mini = INT_MAX;
        for (int i = 1; i <=n; i++) {
            queue<int> q;
            int src = 1;
            visited[src] = true;
            q.push(src);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto x : mp[curr]) {
                    mini = min(mini, x.second);
                    if (!visited[x.first]) {
                        visited[x.first] = true;
                        q.push(x.first);
                    }
                }
            }
            if (visited[n]) {
                return mini;
            }
        }
        return mini;
    }
};