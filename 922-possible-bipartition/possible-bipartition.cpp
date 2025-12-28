class Solution {
public:
    bool bfs(unordered_map<int, vector<int>>& mp, int index, vector<int>& vis) {
        queue<int> q;
        vis[index] = 1;
        q.push(index);
        while (!q.empty()) {
            int front = q.front();
            cout<<front<<endl;
            q.pop();
            for (auto &neigh : mp[front]) {
                if (vis[neigh] == vis[front]) {
                    return false;
                } 
                if(vis[neigh]==-1) {
                    q.push(neigh);
                    vis[neigh]=1-vis[front];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;
        vector<int> vis(n + 1, -1);
        for (int i = 0; i < dislikes.size(); i++) {
            mp[dislikes[i][0]].push_back(dislikes[i][1]);
             mp[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i] == -1) {
                if (bfs(mp, i, vis)==false) {
                    return false;
                }
            }
        }
        return true;
    }
};