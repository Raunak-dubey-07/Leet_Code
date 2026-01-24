class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
      
        queue < pair< int,pair<int, int>>>q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        q.push({0,{0, 0}});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int x = top.second.first;
            int y = top.second.second;
            int d = top.first;
            if (d > dist[x][y])
                continue;
            for (auto& z : dirs) {
                int nx = x + z[0];
                int ny = y + z[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int diff = abs(heights[x][y] - heights[nx][ny]);
                    int maxdiff =max(diff, d);
                    if (dist[nx][ny] > maxdiff) {
                        dist[nx][ny] = maxdiff;
                        q.push({ maxdiff,{nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};