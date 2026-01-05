class Solution {
public:
    void dfs(vector<int>&edges,vector<int>&dist,int node,int distance){
        if(node==-1|| dist[node]!=INT_MAX){
           // cout<<node<<endl;
            return;
        }
        dist[node]=min(dist[node],distance);
        dfs(edges,dist,edges[node],distance+1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        dfs(edges,dist1,node1,0);
        dfs(edges,dist2,node2,0);
        int ans=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]!=INT_MAX && dist2[i]!=INT_MAX){
                //cout<<dist1[i]<<" "<<dist2[i]<<endl;
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