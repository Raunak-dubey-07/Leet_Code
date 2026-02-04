class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int one=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    one++;
                    if(i==n-1 || j==m-1 || i==0 ||j==0){
                        q.push({i,j});
                    }
                }

            }
        }
        int conn=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(grid[x][y]==1){
                grid[x][y]=0;
                conn++;
                if(x+1<n && grid[x+1][y]==1){
                    q.push({x+1,y});
                }
                
                if(x-1>=0 && grid[x-1][y]==1){
                    q.push({x-1,y});
                }
                
                if(y+1<m && grid[x][y+1]==1){
                    q.push({x,y+1});
                }
                
                if(y-1>=0 && grid[x][y-1]==1){
                    q.push({x,y-1});
                }

            }
        }
        return one-conn;
        
    }
};