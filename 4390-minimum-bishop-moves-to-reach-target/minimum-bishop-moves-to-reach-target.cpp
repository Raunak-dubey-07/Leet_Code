class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        queue<pair<int, int>> q;
        q.push({source[0], source[1]});
        int step = 0;
        vector<vector<bool>> vis(9, vector<bool>(9, false));
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int x = q.front().first;
                int y = q.front().second;
                vis[x][y] = true;

                q.pop();
                if (x == target[0] && y == target[1]) {
                    return step;
                }
                int i = x + 1;
                int j = y + 1;
                while (i <= 8 && j <= 8) {
                    if (!vis[i][j]) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                    i++;
                    j++;
                }
                i = x - 1;
                j = y - 1;

                while (i > 0 && j > 0) {
                    if (!vis[i][j]) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                    i--;
                    j--;
                }
                i = x - 1;
                j = y + 1;
                while (i > 0 && j <= 8) {
                    if (!vis[i][j]) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                    i--;
                    j++;
                }
                i = x + 1;
                j = y - 1;
                while (i <= 8 && j > 0) {
                    if (!vis[i][j]) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                    i++;
                    j--;
                }
            }
            step++;
        }
        return -1;
    }
};