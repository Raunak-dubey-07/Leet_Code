class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
                adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dist(n+1,INT_MAX);
        queue<pair<int,int>>q;
        q.push({k,0});
        dist[k]=0;
        vector<bool>visited(n+1,false);
        visited[k]=true;
        while(!q.empty()){
            int front=q.front().first;
            int wt=q.front().second;
            q.pop();
            for(auto x:adj[front]){
                if(!visited[x.first] || dist[front]+x.second<dist[x.first]){
                visited[x.first]=true;
                dist[x.first]=dist[front]+x.second;
                cout<<x.first<<" "<<dist[x.first]<<endl;
                q.push({x.first,dist[x.first]});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(dist[i],maxi);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                return -1;
            }
        }
        return maxi;
    }
};