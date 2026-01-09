class Solution {
public:
    int ans = INT_MIN;
    void dfs(vector<int>& edges, vector<bool>& visited, int s,
             vector<int>& number, vector<bool>& rec) {
        if (s != -1) {
            visited[s] = true;
            rec[s] = true;
            int v = edges[s];
           
            if (v >= 0 && visited[v] == false) {
                 number[v] = number[s] + 1;
                dfs(edges, visited, v, number, rec);
            } else if (v >= 0 && rec[v]) {
                ans = max(ans, number[s] - number[v] + 1);
            }
            rec[s] = false;
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> number(n, 0);
        vector<bool> visited(n, false);
        vector<bool> rec(n, false);
        for (int i = 0; i < n; i++) {
            int count = 0;
            if (!visited[i]) {
                dfs(edges, visited, i, number, rec);
            }
        }
        if (ans == INT_MIN) {
            return -1;
        }
        return ans;
    }
};