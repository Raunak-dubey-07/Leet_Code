class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    void Union(int u,int v){
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(u!=v){
            if(rank[u]<rank[v]){
                parent[u]=v;
                rank[v]=rank[v]+rank[u]+1;
            }
            else if(rank[v]<rank[u]){
                parent[v]=u;
                rank[u]=rank[u]+rank[v]+1;
            }
            else{
                parent[v]=u;
                rank[u]=2*rank[u]+1;
            }
        }

    }
    int findParent(vector<int>&parent,int u){
        //cout<<u<<endl;
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findParent(parent,parent[u]);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;

        }
        for(int i=0;i<edges.size();i++){
            int u=findParent(parent,edges[i][0]);
            int v=findParent(parent,edges[i][1]);
            if(u!=v){
                Union(u,v);
            }
        }
        long long prev=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            int u=findParent(parent,i);
             cout<<u<<endl;
            if(rank[u]>=0){
                 cout<<"rank "<<rank[u]+1<<endl;
                ans+=(prev*(rank[u]+1));
                prev+=(rank[u]+1);
                rank[u]=-1;
            }
        }
        return ans;
    }
};