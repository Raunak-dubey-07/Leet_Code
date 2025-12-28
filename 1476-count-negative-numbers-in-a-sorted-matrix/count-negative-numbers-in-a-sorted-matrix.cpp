class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int i=0;
        int j=grid[0].size()-1;
        int c=0;
        while(i<n && j>=0){
            if(grid[i][j]<0){
                c+=(n-i);
                j--;
            }
            else{
                i++;
            }
        }
        return c;
    }
};