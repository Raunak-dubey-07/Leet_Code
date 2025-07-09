class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n = boxGrid.size();
        int m = boxGrid[0].size();
        
        for (int i = 0; i < n; i++) {
            int support=m;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    boxGrid[i][j]='.';
                    boxGrid[i][support-1]='#';
                    support--;
                }
                else if(boxGrid[i][j]=='*'){
                    support=j;
                }
            }
           
        }
        vector<vector<char>> ans;
        for (int i = 0; i < m; i++) {
            vector<char> res;
            for (int j = n - 1; j >= 0; j--) {
                res.push_back(boxGrid[j][i]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};