class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        while (!q.empty()) {
            pair<int, int> front = q.front().first;
            int time = q.front().second;
            q.pop();
            ans = max(ans, time);
            if (front.first + 1 < m && !vis[front.first + 1][front.second] &&
                grid[front.first + 1][front.second] == 1) {
                q.push({{front.first + 1, front.second}, time + 1});
                vis[front.first + 1][front.second] = true;
            }
            if (front.second + 1 < n && !vis[front.first][front.second + 1] &&
                grid[front.first][front.second + 1] == 1) {
                q.push({{front.first, front.second + 1}, time + 1});
                vis[front.first][front.second + 1] = true;
            }
            if (front.first - 1 >= 0 && !vis[front.first - 1][front.second] &&
                grid[front.first - 1][front.second] == 1) {
                q.push({{front.first - 1, front.second}, time + 1});
                vis[front.first - 1][front.second] = true;
            }
            if (front.second - 1 >= 0 && !vis[front.first][front.second - 1] &&
                grid[front.first][front.second - 1] == 1) {
                q.push({{front.first, front.second-1}, time + 1});
                vis[front.first][front.second - 1] = true;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};