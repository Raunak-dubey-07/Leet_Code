class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < flights.size(); i++) {
            mp[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int step = 0;
        while (!q.empty() && step<=k) {
            int n = q.size();
            while (n--){
                auto front = q.front();
            q.pop();
            for (auto& child : mp[front.first]) {
                cout << "child "<<child.first << endl;
                if ((front.second + child.second) < dist[child.first]) {
                    dist[child.first] = front.second + child.second;
                    q.push({child.first,dist[child.first]});
                    //cout << dist[child.first] << endl;
                }
    
            }
        }
        step++;
    }
    if(dist[dst]!=INT_MAX){
        return dist[dst];
    }
    return -1;
    
}
}
;