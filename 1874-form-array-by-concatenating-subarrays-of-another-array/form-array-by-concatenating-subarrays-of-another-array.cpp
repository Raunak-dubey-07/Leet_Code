class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n=groups.size();
        int o=nums.size();
        int i=0,j=0,k=0,match=0;
        int c=0;
        while(i<n){
            int m=groups[i].size();
            j=0;
                while(k<o && j<m){
                    if(groups[i][j]==nums[k]){
                        j++;
                        k++;
                    }
                    else{
                        c++;
                        j=0;
                        k=c;
                    }
                }
                c=k-1;
                i++;
        }
        if(i==n && j==groups[n-1].size()){
            return true;
        }
        return false;
        
    }
};