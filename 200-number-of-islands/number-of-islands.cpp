class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis,int n,int m){
        if(i<0 || j<0 ||i>=n || j>=m || vis[i][j] || grid[i][j]!='1'){
            return;
    }
    vis[i][j]=true;
    dfs(i,j+1,grid,vis,n,m);
    dfs(i+1,j,grid,vis,n,m);
    dfs(i-1,j,grid,vis,n,m);
    dfs(i,j-1,grid,vis,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {

        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        long long island=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis,grid.size(),grid[0].size());
                    island++;
                }
            }
        }
        return island;

        
    }
};