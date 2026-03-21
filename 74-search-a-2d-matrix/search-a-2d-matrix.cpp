class Solution {
public:
    int rowfind(vector<vector<int>>& matrix, int target){
        int i=0;
        int j=matrix.size()-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
           if(matrix[mid][0] <= target){
    ans = mid;
    i = mid + 1;
}
else{
    j = mid - 1;
}
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=rowfind(matrix,target);
        if(i==-1){
            return false;
        }
        int j=0;
        int k=matrix[i].size()-1;
        while(j<=k){
            int mid=(j+k)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid]<target){
                j=mid+1;
            }
            
            else{
                k=mid-1;
            }

        }
        return false;
    }
};