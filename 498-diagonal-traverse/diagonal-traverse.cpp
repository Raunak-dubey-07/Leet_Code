class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
           int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n+m-1);
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=i+j;
                ans[idx].push_back(mat[i][j]);
                
            }
        }
        vector<int>res;
        for(int i=0;i<ans.size();i++){
              if(i%2==0)
            reverse(ans[i].begin(),ans[i].end());
            for(int j=0;j<ans[i].size();j++){
                res.push_back(ans[i][j]);
            }
        }
        
        return res;
        
    }
};