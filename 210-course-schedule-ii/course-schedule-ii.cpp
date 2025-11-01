class Solution {
public:
    bool iscycle(int v, unordered_map<int, vector<int>>& adj, vector<bool>& vis,
                 vector<bool>& recPath) {
        vis[v] = true;
        recPath[v] = true;
        for (int x : adj[v]) {
            if (!vis[x]) {
                if (iscycle(x, adj, vis, recPath)) {
                    return true;
                }
            } else if (recPath[x]) {
                return true;
            }
        }
        recPath[v] = false;
        return false;
    }
    void dfs(int v, unordered_map<int, vector<int>>& adj, vector<bool>& vis,
             vector<int>& ans) {
        vis[v] = true;
        for (int x : adj[v]) {
            if (!vis[x]) {
                dfs(x, adj, vis, ans);
            }
        }
        ans.push_back(v);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto& e : prerequisites) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        vector<bool> vis1(numCourses, false);
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!iscycle(i, adj, vis1, recpath)) {
                    dfs(i, adj, vis, ans);
                }
                else{
                    return { };
                }
            }
        }
        return ans;
    }
};