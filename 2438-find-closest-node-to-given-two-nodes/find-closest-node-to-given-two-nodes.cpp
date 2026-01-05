class Solution {
public:
    void dfs(vector<int>&edges,vector<int>&visited,vector<int>&dist,int node,int distance){
        if(node==-1|| visited[node]==true){
           // cout<<node<<endl;
            return;
        }
        visited[node]=true;
        dist[node]=min(dist[node],distance);
        dfs(edges,visited,dist,edges[node],distance+1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>visited1(n,0);
        vector<int>visited2(n,0);
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        dfs(edges,visited1,dist1,node1,0);
        //visited.clear();
        //cout<<visited[2]<<endl;
        dfs(edges,visited2,dist2,node2,0);
        int ans=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            //cout<<dist1[i]<<" "<<dist2[i]<<endl;
            if(dist1[i]!=INT_MAX && dist2[i]!=INT_MAX){
                cout<<dist1[i]<<" "<<dist2[i]<<endl;
                int prevans=ans;
            ans=min(ans,max(dist1[i],dist2[i]));
            if(ans!=prevans){
                idx=i;

            }
            }
        }
        return idx;
        
        
    }
};