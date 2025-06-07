class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0){
                        grid[i][j]=grid[i][j]+1;
                    }
                    else{
                        grid[i][j]=grid[i][j]-1;
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                //cout<<j<<' '<<i<<' '<<grid[j][i]<<endl;
                if(grid[j][i]==0){
                    c++; 
                }
            }
            // cout<<c<<endl;
            if(c>(n/2)){
                for(int j=0;j<n;j++){
                    if(grid[j][i]==0){
                       // cout<<j<<' '<<i<<' '<<grid[j][i]<<endl;
                        grid[j][i]=1;
                    }
                    else{
                        grid[j][i]=0;
                    }
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int k=1;
            for(int j=m-1;j>=0;j--){
                //cout<<grid[i][j]<<endl;
                //cout<<k<<" "<<grid[i][j]<<endl;
                //out<<k*grid[i][j]<<endl;
                sum=sum+k*grid[i][j];
                k=pow(2,m-1-j+1);
                //cout<<k<<endl;
            }
            //cout<<sum<<endl;
        }
        return sum;
        
    }
};